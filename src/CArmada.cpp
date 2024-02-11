/*
 * CArmada.cpp
 *
 *  Created on: Jan 31, 2024
 *      Author: tom
 */

#include "CArmada.h"

/**
 * Constructeur par défaut.
 */
CArmada::CArmada(){
	vector<CBateau> m_listeBateaux(0);
}

/**
 * Ajoute un bateau à la collection.
 * @param unBat Référence vers le bateau à ajouter.
 */
void CArmada::ajouterBateau(CBateau& unBat) {
    // Pré-condition : Vérifier que le bateau à ajouter est correctement défini
    if (unBat.getNom() == "néant" || unBat.getTaille() <= 0) {
        cout << "CArmada::ajouterBateau : Le bateau n'est pas correctement défini." << endl;
        return;
    }


	// Ajouter le bateau à la collection	
	this->m_listeBateaux.push_back(unBat);
}


/**
 * Renvoie un pointeur vers le bateau à l'index spécifié.
 *
 * @param i Index du bateau dans la collection (0 <= i < taille). 
 * 
 * @return Pointeur vers le bateau ou nullptr si l'index est invalide.
 */
CBateau* CArmada::getBateau(int i) {
    // Pré-condition : Vérifier que l'index est valide
	if (i < 0 || i >= this->m_listeBateaux.size()) {
        cout << "CArmada::getBateau : Index invalide pour récupérer le bateau." << endl;
        return nullptr;
    }

    // Récupérer et renvoyer le pointeur vers le bateau à l'index spécifié
    return &this->m_listeBateaux[i];
}


/**
 * Renvoie le nombre total de bateaux dans l'armada.
 * 
 * @return Nombre total de bateaux.
 */
int CArmada::getEffectifTotal(){
	return this->m_listeBateaux.size();
}

/**
 * Renvoie le nombre total de cases occupées par l'armada.
 * 
 * @return Nombre total de cases occupées.
 */
int CArmada::getNbreTotCases(){
	int nbCases = 0;

	// Pré-condition : Vérifier que la liste des bateaux n'est pas vide
	if (this->m_listeBateaux.empty()) {
		cout << "CArmada::getNbreTotCases : Aucun bateau dans l'armada." << endl;
        return 0;
	} 

    // Itération sur la liste
    for(CBateau boat : this->m_listeBateaux){
        nbCases += boat.getTaille();
    }

	return nbCases;
}

/**
 * Renvoie le nombre de bateaux non coulés dans l'armada.
 * 
 * @return Nombre de bateaux non coulés.
 */
int CArmada::getEffectif(){

	// Pré-condition : Vérifier que la liste des bateaux n'est pas vide
	if (this->m_listeBateaux.empty()) {
		cout << "CArmada::getEffectif : Aucun bateau dans l'armada." << endl;
	}

	int addEffectif = 0;
    // Forme d'itération pour la liste vector
    for(CBateau boat : this->m_listeBateaux){
        if(!boat.estCoule()){
            addEffectif++;
        }
    }

	return addEffectif;
}

/**
 * Lit la configuration de l'armada à partir d'un fichier texte.
 */
void CArmada::getArmadaFromFile() {
    // Vérifier si le fichier flotille.txt est présent dans le répertoire /datas
    ifstream fichier("../datas/flotille.txt");
    if (!fichier.is_open()) {
        cout << "CArmada::getArmadaFromFile : Impossible d'ouvrir le fichier flotille.txt." << endl;
        return;
    }

    // Lecture du fichier ligne par ligne
    string ligne;
    while (getline(fichier, ligne)) {
        // Ignorer les lignes de commentaire commençant par '#'
        if (ligne.size() > 0 && ligne[0] != '#') {
            // Utiliser un flux de chaînes pour lire les données de chaque ligne
            std::istringstream iss(ligne);
            std::string nom;
            int nombreSurGrille, nombreCasesHorizontales;
            // Extraire les données de la ligne (nom, nombreSurGrille, nombreCasesHorizontales)
            iss >> nom >> nombreSurGrille >> nombreCasesHorizontales;
            // Créer un nouveau bateau avec les données extraites
            CBateau nouveauBateau(nom, std::make_pair(0, 0), nombreCasesHorizontales);
            // Ajouter le nouveau bateau à l'armada le nombre de fois spécifié par nombreSurGrille
            for (int i = 0; i < nombreSurGrille; ++i) {
                ajouterBateau(nouveauBateau);
            }
        }
    }
    fichier.close(); // Fermer le fichier après lecture

    // Vérifier si tous les bateaux ont été ajoutés à l'armada
    if (getEffectifTotal() == 0) {
        cout << "CArmada::getArmadaFromFile : Aucun bateau n'a été ajouté à l'armada à partir du fichier flotille.txt." << endl;
    }
}


/**
 * Place aléatoirement tous les bateaux sur la grille.
 * 
 * @return True si le placement automatique a réussi, sinon False.
 */
bool CArmada::placerAleatoirement() {
    // Vérifier si l'armada est vide
    if (this->m_listeBateaux.empty()) {
        cout << "CArmada::placerAleatoirement : Aucun bateau dans l'armada." << endl;
        return false;
    }

    // Initialiser le booléen pour le placement des bateaux
    bool estPlace = false;
    int compteurBateaux = 0;
    // Vecteur pour stocker les positions prises sur la grille
    vector<pair<int,int>> positionsPrises(getNbreTotCases());

    // Tant que tous les bateaux ne sont pas placés et que le nombre de tentatives est inférieur à MAXESSAIS
    while (compteurBateaux < m_listeBateaux.size()) {
        bool estPositionne = false;
        int tentatives = 0;

        // Tant que le bateau n'est pas placé et que le nombre de tentatives est inférieur à MAXESSAIS
        while (tentatives < MAXESSAIS && !estPositionne) {
            // Générer des coordonnées aléatoires pour le point d'ancrage du bateau
            int x = rand() % (TAILLE_GRILLE - 1);
            int y = rand() % (TAILLE_GRILLE - m_listeBateaux.at(compteurBateaux).getTaille());

            // Vérifier si la position est occupée
            bool estOccupe = false;

            // Parcourir les positions prises pour vérifier l'occupation
            for (pair<int,int> pos : positionsPrises) {
                if (pos.first == x) {
                    for (int y2 = 0; y2 < m_listeBateaux.at(compteurBateaux).getTaille(); y2++) {
                        if (pos.second == (y + y2)) {
                            estOccupe = true;
                            break;
                        }
                    }
                }
            }

            // Si la position n'est pas occupée, placer le bateau
            if (!estOccupe) {
                estPositionne = true;
                // Définir la position du bateau
                m_listeBateaux.at(compteurBateaux).setPosition(x, y);

                // Ajouter les positions occupées par le bateau dans positionsPrises
                for (int z = 0; z < m_listeBateaux.at(compteurBateaux).getTaille(); z++) {
                    positionsPrises.push_back(make_pair(x, y + z));
                }

                // Passer au bateau suivant
                compteurBateaux++;
            }

            tentatives++;
        }

        // Si le nombre de tentatives atteint MAXESSAIS, sortir de la boucle
        if (tentatives >= MAXESSAIS)
            break;
    }

    // Si tous les bateaux ont été placés, mettre estPlace à true
    if (compteurBateaux == m_listeBateaux.size()) {
        estPlace = true;
    }

    return estPlace;
}
