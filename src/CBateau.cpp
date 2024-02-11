/*
 * CBateau.cpp
 *
 *  Created on: Jan 30, 2024
 *      Author: tom
 */

#include "CBateau.h"

/**
 * Constructeur par défaut.
 */
CBateau::CBateau() {
    this->m_taille = 0;
    this->m_nom = "néant";
    this->m_positions = make_pair(0, 0);
    this->m_pDegats = nullptr;
}

/**
 * Constructeur avec paramètres.
 * 
 * @param n Nom du bateau.
 * @param p Position du bateau.
 * @param t Taille du bateau.
*/
CBateau::CBateau(string n, pair<int, int> p, int t) {
    // Pré-condition : Vérifier que la taille du bateau est supérieure à zéro
    if (t <= 0) {
        cout << "CBateau::CBateau(param) : La taille du bateau doit être supérieure à zéro." << endl;
        return;
    }

    // Pré-condition : Vérifier que la position du bateau est valide
    if (p.first < 0 || p.second < 0) {
        cout << "CBateau::CBateau(param) : La position du bateau est invalide." << endl;
        return;
    }

    // Pré-condition : Vérifier que le nom du bateau est défini
    if (n == "néant"){
        cout << "CBateau::CBateau(param) : Le bateau n'a pas de nom défini" << endl;
        return;
    }

    this->m_taille = t;
    this->m_nom = n;
    this->m_positions = p;
    // Allouer dynamiquement un tableau de booléens pour stocker l'état des dégâts
    this->m_pDegats = new bool[this->m_taille]{false};
}

/**
 * Constructeur de copie.
 * 
 * @param positionToCopy Référence constante vers l'objet à copier.
*/
CBateau::CBateau(const CBateau& positionToCopy) {

    //Prédiction : Vérifier que la taille du bateau est supérieure à zéro
    if (positionToCopy.m_taille <= 0) {
        cout << "CBateau::CBateau(copy) : La taille du bateau doit être supérieure à zéro." << endl;
        return;
    }

    // Copier les attributs de l'objet à copier dans l'objet courant
    this->m_taille = positionToCopy.m_taille;
    this->m_nom = positionToCopy.m_nom;
    this->m_positions = positionToCopy.m_positions;
    this->m_pDegats = new bool[this->m_taille]{false};

    for (int i = 0; i < this->m_taille; ++i) {
        this->m_pDegats[i] = positionToCopy.m_pDegats[i];
    }
}

/**
 * Méthode pour obtenir l'état des dégâts sur une case du bateau.
 * 
 * @param i Index de la case.
 * 
 * @return true si la case est touchée, false sinon.
 */
bool CBateau::getDegats(int i) {
    // Pré-condition : Vérifier que l'index est valide
    if (i < 0 || i >= m_taille) {
        cout << "CBateau::getDegats : Index invalide pour obtenir l'état des dégâts sur une case du bateau." << endl;
        return false;
    }

    // Renvoyer l'état des dégâts sur la case i (Comme 0 et 1 sont des booléens, on peut les renvoyer directement)
    return this->m_pDegats[i];
}

/**
 * Méthode pour obtenir le nom du bateau.
 * 
 * @return Nom du bateau.
 */
string CBateau::getNom() {
    return this->m_nom;
}

/**
 * Méthode pour obtenir la taille du bateau.
 * 
 * @return Taille du bateau.
 */
int CBateau::getTaille() {
    return this->m_taille;
}

/**
 * Méthode pour obtenir la position du bateau sur la grille.
 * 
 * @return Position du bateau.
 */
pair<int, int> CBateau::getPosition() {
    return this->m_positions;
}

/**
 * Méthode pour obtenir la position horizontale du bateau sur la grille.
 * 
 * @param i Position horizontale du bateau.
 * @param j Position verticale du bateau.
 * 
 * @return Position horizontale du bateau.
 */
void CBateau::setPosition(int i, int j) {
    // Pré-condition : Vérifier que les positions sont dans la grille
    if (i < 0 || j < 0 || i >= TAILLE_GRILLE || j >= TAILLE_GRILLE) {
        cout << "CBateau::setPosition : Position incorrecte, emplacement hors de la grille ou dépacement de la grille.";
        cout << "Aucun changement réalisé." << endl;
        return;
    }

    // Mettre à jour la position du bateau
    this->m_positions = make_pair(i, j);
}

/**
 * Méthode pour vérifier si le bateau est coulé.
 * 
 * @return true si le bateau est coulé, false sinon.
 */
bool CBateau::estCoule() {

    // Pré-condition : Vérifier que le tableau des dégâts est initialisé
    if (this->m_pDegats == nullptr) {
        cout << "CBateau::estCoule : Tableau des dégâts non initialisé." << endl;
        return false;
    }

    // Parcourir le tableau des dégâts
    for (int i = 0; i < m_taille; ++i) {
        // Si au moins une case n'est pas touchée, le bateau n'est pas coulé
        if (this->m_pDegats[i] == false) {
            return false;
        }
    }
    // Toutes les cases sont touchées, le bateau est coulé
    return true;
}

/**
 * Méthode pour gérer un tir adverse.
 * 
 * @param p Coordonnées du tir.
 * 
 * @return true si le tir est victorieux, false sinon.
 */
bool CBateau::tirAdverse(pair<int, int> p) {
    int i = p.first;
    int j = p.second;

    // Pré-condition : Vérification de la positivité des indices
    if(i < 0 || j < 0){
        cout << "CBateau::tirAdverse : Les positions indiquées pour le tir sont hors de la grille." << endl;
        return false;
    }

    // Vérifier si la coordonnée passée en paramètre est un tir victorieux
    if (i == this->m_positions.first && j >= this->m_positions.second && j < this->m_positions.second + m_taille) {
        int indiceDegats = j - this->m_positions.second;
        // Vérifier si la case n'a pas déjà été touchée
        if (!this->m_pDegats[indiceDegats]) {
            // Marquer la case comme touchée et renvoyer vrai (tir victorieux)
            this->m_pDegats[indiceDegats] = true;
            return true;
        }
    }
    // Si la case est déjà touchée, renvoyer faux (pas de tir victorieux)
    return false;
}

/**
 * Opérateur de flux de sortie.
 * 
 * @param os Flux de sortie.
 * @param theB Référence constante vers le bateau à afficher.
 * 
 * @return Flux de sortie.
 */
ostream& operator<<(ostream& os, CBateau& theB) {
    // Pré-condition : Vérifier que le bateau a été correctement initialisé
    if (theB.m_taille <= 0 || theB.m_nom == "néant") {
        cout << "CBateau::operator<< : Le bateau n'est pas correctement défini." << endl;
        return os;
    }

    // Afficher les informations du bateau
    os << "Nom du bateau : " << theB.m_nom << endl;
    os << "Taille du bateau : " << theB.m_taille << endl;
    os << "Position du bateau : (" << theB.m_positions.first << ", " << theB.m_positions.second << ")" << endl;
    os << "État des dégâts : {";
    for (int i = 0; i < theB.m_taille; ++i) {
        os << theB.m_pDegats[i] << " ";
    }
    os << "}" << endl;
    return os;
}

/**
 * Opérateur d'affectation. On surcharge l'opérateur '='.
 * 
 * @param positionToCopy Référence constante vers l'objet à copier.
 */
void CBateau::operator=(const CBateau& positionToCopy) {
    // Pré-condition : Vérifier que la taille du bateau est supérieure à zéro
    if (positionToCopy.m_taille <= 0) {
        cout << "CBateau::operator= : La taille du bateau doit être supérieure à zéro." << endl;
        return;
    }

    this->m_taille = positionToCopy.m_taille;
    this->m_nom = positionToCopy.m_nom;
    this->m_positions = positionToCopy.m_positions;
    this->m_pDegats = new bool[this->m_taille]{false};

    for (int i = 0; i < this->m_taille; ++i) {
        this->m_pDegats[i] = positionToCopy.m_pDegats[i];
    }
}

/**
 * Destructeur.
 */
CBateau::~CBateau() {
	// Libérer la mémoire allouée dynamiquement
	delete[] this->m_pDegats;
	this->m_pDegats = nullptr;
}
