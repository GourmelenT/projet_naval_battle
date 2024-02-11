/*
 * CGui.cpp
 *
 *  Created on: Jan 31, 2024
 *      Author: tom
 */

#include "CGui.h"

 /**
 * Constructeur par défaut
 * 
 * m_pArmada et m_pCoups sont initialisés à nullptr
 */
CGui::CGui(){
    this->m_pArmada = nullptr;
    this->m_pCoups = nullptr;
}

/**
 * Constructeur qui reçoit un pointeur vers l'armada et un 
 * pointeur sur la structure d'enregistrement des coups
 * 
 * @param pArmada : pointeur vers l'armada
 * @param pCoups : pointeur vers les coups
 */
CGui::CGui(CArmada* pArmada, CCoups* pCoups){
    //Pré-condition : pArmada et pCoups sont non nuls
    if(pArmada == nullptr || pCoups == nullptr){
        cout << "CGui::CGui : pArmada et pCoups sont non nuls" << endl;
        return;
    }

    this->m_pArmada = pArmada;
    this->m_pCoups = pCoups;
}

/**
 * Destructeur
 * 
 * Destruction des zones pointées par m_pArmada et m_pCoups
 */
CGui::~CGui(){
    //Pré-condition : m_pArmada et m_pCoups sont non nuls
    if(m_pArmada == nullptr || m_pCoups == nullptr){
        cout << "CGui::~CGui : m_pArmada et m_pCoups sont non nuls" << endl;
        return;
    }

    delete m_pArmada;
    delete m_pCoups;
}

/**
 * Modificateur : Mise à jour des attributs m_pArmada et m_pCoups 
 * 
 * @param pArmada : pointeur vers l'armada
 * @param pCoups : pointeur vers les coups
 */
void CGui::setArmadaCoups(CArmada* pArmada, CCoups* pCoups){
    //Pré-condition : pArmada et pCoups sont non nuls
    if(pArmada == nullptr || pCoups == nullptr){
        cout << "CGui::setArmada : pArmada et pCoups sont non nuls" << endl;
        return;
    }
    
    // Modification des attributs
    this->m_pArmada = pArmada;
    this->m_pCoups = pCoups;
}

/**
 * Méthode appelée au début du jeu pour positionner tous les bateaux
 * sur la grille en éxécutant placeAleatoirement() de CArmada
 * 
 * @return false si le positionnement a échoué
 */
bool CGui::positionnerBateaux(){
    //Pré-condition : m_pArmada est non nul
    if(this->m_pArmada == nullptr){
        cout << "CGui::positionnerBateaux : m_pArmada est non nul" << endl;
        return false;
    }

    // Appel de placeAleatoirement() de CArmada
    if(!this->m_pArmada->placerAleatoirement()){
        return false;
    }

    return true;
}

/**
 * Saisie de la coordonnée (ligne, colonne) de l'attaque (vérfication 
 * ogligatoire bon/mauvais après saisie de la coordonnée par l'utilisateur)
 * 
 * @return la coordonnée de l'attaque
 */
pair<int, int> CGui::choisirAttaque() {
    int ligne, colonne;
    string input;

    cout << "Saisir la ligne de l'attaque : ";
    getline(cin, input);

    // Vérification de l'entrée pour s'assurer qu'elle est composée uniquement de chiffres
    while (input.find_first_not_of("0123456789") != string::npos || input.empty()) {
        cout << "Erreur : Vous devez saisir un entier pour la ligne." << endl;
        cout << "Saisir la ligne de l'attaque : ";
        getline(cin, input);
    }
    ligne = stoi(input);

    cout << "Saisir la colonne de l'attaque : ";
    getline(cin, input);

    // Vérification de l'entrée pour s'assurer qu'elle est composée uniquement de chiffres
    while (input.find_first_not_of("0123456789") != string::npos || input.empty()) {
        cout << "Erreur : Vous devez saisir un entier pour la colonne." << endl;
        cout << "Saisir la colonne de l'attaque : ";
        getline(cin, input);
    }
    colonne = stoi(input);

    // Vérification de la validité de la coordonnée
    if (ligne < 0 || ligne >= TAILLE_GRILLE || colonne < 0 || colonne >= TAILLE_GRILLE) {
        cout << "Coordonnée incorrecte, veuillez saisir une coordonnée valide." << endl;
        return choisirAttaque();
    }

    // Demandé s'il valide les coordonnées
    char reponse;
    cout << "Vous avez choisi la coordonnée (" << ligne << ", " << colonne << ").\n Souhaitez vous continuer ? (o/n) : ";
    cin >> reponse;
    cout << endl;

    // Vérification de la réponse
    if (reponse == 'o') {
         // Effacer le flux d'entrée pour éviter les problèmes de saisie supplémentaire
        cin.ignore();
        return make_pair(ligne, colonne);
    } else {
        // Effacer le flux d'entrée pour éviter les problèmes de saisie supplémentaire
        cin.ignore();
        return choisirAttaque();
    }
}


/**
 * Affiche la partie est gagnée à l'écran 
 */
void CGui::afficheGagne(){
    // Couleurs pour le shell
    const string ORANGE = "\033[1;33m";
    const string VIOLET = "\033[1;36m";
    const string VERT = "\033[1;32m";
    const string RESET = "\033[0m";

    // Affichage du message de félicitations
    cout << ORANGE << "#**********************************#" << endl;
    cout << ORANGE << "#                                  #" << endl;
    cout << ORANGE << "# " << VIOLET << "            ! BRAVO !            " << ORANGE << "#" << endl;
    cout << ORANGE << "# " << VERT << "       -Vous avez gagné -        " << ORANGE << "#" << endl;
    cout << ORANGE << "#                                  #" << endl;
    cout << ORANGE << "#**********************************#" << RESET << endl;

}

/**
 * Affiche la partie est perdue à l'écran 
 */
void CGui::affichePerdu(){
    // Couleurs pour le shell
    const string ORANGE = "\033[1;33m";
    const string VIOLET = "\033[1;36m";
    const string ROUGE = "\033[1;31m";
    const string RESET = "\033[0m";

    // Affichage du message de félicitations
    cout << ORANGE << "#**********************************#" <<  endl;
    cout << ORANGE << "#                                  #" <<  endl;
    cout << ORANGE << "#" << VIOLET << "       ! UNE PROCHAINE FOIS !     "<< ORANGE << "#" <<  endl;
    cout << ORANGE << "#" << ROUGE <<"        - Vous avez perdu -       "<< ORANGE << "#" <<  endl;
    cout << ORANGE << "#                                  #" <<  endl;
    cout << ORANGE << "#**********************************#" << RESET << endl;
}


/**
 * Remplissage des deux grilles (la grille de l'attaquant et la grille
 * de l'adversaire) avec les bateaux et les coups joués
 * 
 * @param os : le flux de sortie
 */
void CGui::remplirDeuxGrilles(ostream& os) {
    // Remplir la grille du joueur
    for (int i = 0; i < TAILLE_GRILLE - 1; i++) {
        for (int j = 0; j < TAILLE_GRILLE - 1; j++) {
            char symbol = '-'; // Symbole par défaut : case vide

            // Vérifier si la case a été touchée par un tir adverse
            for (int k = 0; k < m_pCoups->getTaille("ploufAdverse"); k++) {
                if (m_pCoups->getPair("ploufAdverse", k) == make_pair(i, j)) {
                    symbol = 'O'; // Case touchée par un tir adverse
                    break;
                }
            }

            if (symbol == '-') {
                // Vérifier si la case correspond à un bateau non touché ou touché
                for (int k = 0; k < m_pArmada->getEffectifTotal(); k++) {
                    for (int l = 0; l < m_pArmada->getBateau(k)->getTaille(); l++) {
                        pair<int, int> pos = m_pArmada->getBateau(k)->getPosition();
                        if (pos.first == i && pos.second + l == j) {
                            if (m_pArmada->getBateau(k)->getDegats(l)) {
                                symbol = 'X'; // Case touchée d'un bateau
                            } else {
                                symbol = 'B'; // Case d'un bateau non touchée
                            }
                            break;
                        }
                    }
                    if (symbol != '-') break; // Sortir de la boucle interne si la case a été trouvée
                }
            }

            m_grilleJou[i][j] = symbol; // Assigner le symbole à la case de la grille du joueur
        }
    }

    // Afficher la grille du joueur
    afficherLaGrille(os, "joueur");

    // Remplir la grille de l'adversaire
    for (int i = 0; i < TAILLE_GRILLE - 1; i++) {
        for (int j = 0; j < TAILLE_GRILLE - 1; j++) {
            char symbol = '-'; // Symbole par défaut : case vide

            // Vérifier si la case a été touchée par un tir du joueur
            for (int k = 0; k < m_pCoups->getTaille("dansLEau"); k++) {
                if (m_pCoups->getPair("dansLEau", k) == make_pair(i, j)) {
                    symbol = 'O'; // Case touchée par un tir du joueur
                    break;
                }
            }

            if (symbol == '-') {
                // Vérifier si la case a été touchée par un tir du joueur et a touché un bateau adverse
                for (int k = 0; k < m_pCoups->getTaille("touche"); k++) {
                    if (m_pCoups->getPair("touche", k) == make_pair(i, j)) {
                        symbol = 'X'; // Case touchée par un tir du joueur et touche un bateau adverse
                        break;
                    }
                }
            }

            m_grilleAdv[i][j] = symbol; // Assigner le symbole à la case de la grille de l'adversaire
        }
    }

    // Afficher la grille de l'adversaire
    afficherLaGrille(os, "adversaire");
}


/**
 * Affichage d'une grille (joueur ou adversaire) à l'écran, 
 * c'est-à-dire affichage du contenu de m_grilleJou ou 
 * m_grilleAdv + les légendes (0...TAILLE_GRILLE-2).
 * 
 * @param os : le flux de sortie
 * @param jouOuAdv : "joueur" ou "adversaire"
 */
void CGui::afficherLaGrille(ostream& os, string jouOuAdv) {
    // Affichage du titre de la grille
    if (jouOuAdv == "joueur") {
        os << "\nGrille joueur :\n" << endl;
    } else {
        os << "Grille adverse :\n" << endl;
    }

    // Affichage de l'index des colonnes
    os << " ";
    for (int i = 0; i < TAILLE_GRILLE - 1; i++) {
        os << "   " << i;
    }
    os << "\n" << endl;

    // Parcours de la grille
    for (int i = 0; i < TAILLE_GRILLE - 1; i++) {
        os << i; // Affichage de l'index de la ligne

        // Parcours des colonnes
        for (int j = 0; j < TAILLE_GRILLE - 1; j++) {
            // Affichage du symbole correspondant à l'état de la case
            if (jouOuAdv == "joueur") {
                os << "   " << m_grilleJou[i][j]; // Affichage de la grille du joueur
            } else {
                os << "   " << m_grilleAdv[i][j]; // Affichage de la grille adverse
            }
        }
        os << "\n" << endl; // Retour à la ligne après chaque ligne de la grille
    }

    // Affichage de la légende
    os << "Légende : " << endl;
    os << "   - : case vide" << endl;
    os << "   O : dans l'eau" << endl;
    os << "   B : bateau non touché" << endl;
    os << "   X : bateau touché" << endl;

    os << "\n" << endl; // Ligne vide à la fin de l'affichage de la grille
}


/**
 * Surcharge de l'opérateur << pour afficher les deux grilles
 * Cette fonction fait un simple appel à remplirDeuxGrilles() 
 * de l'objet theG.
 * 
 * @param os : le flux de sortie
 * @param theG : l'objet à afficher
 * 
 * @return le flux de sortie
 */
ostream& operator<< (ostream& os, CGui& theG) {
    theG.remplirDeuxGrilles(os);
	return os;
}

