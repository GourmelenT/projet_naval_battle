/*
 * testCBateau.cpp
 *
 *  Created on: Jan 31, 2024
 *      Author: tom
 */

#include "CBateau.h"

void testConstructeur();
void testAccesseur();
void testModificateurs();
void testEstCoule();
void testTirAdverse();
void testDestructeur();


// Méthode principale
int main() {

	testConstructeur();
	// testAccesseur();
	// testModificateurs();
	// testEstCoule();
	// testTirAdverse();
	// testDestructeur();
	// testOperator();

	return 0;
}


void testConstructeur() {
    // ### Test du constructeur par défaut ###
    CBateau bateau1;
    cout << "Test du constructeur par défaut : \n" << bateau1 << endl;


    // ### Test du constructeur avec paramètres ###
    // ---- Cas normal ----
    CBateau bateau2("Porte-avion", make_pair(1, 2), 4);
    cout << "Test du constructeur avec paramètres (cas normal) : \n" << bateau2 << endl;

    // ---- Cas limites ----
    // Taille minimale
    CBateau bateau3("Petit Bateau", make_pair(5, 5), 1);
    cout << "Test du constructeur avec paramètres (cas limite - taille minimale) : \n" << bateau3 << endl;

    // Positions aux limites
    CBateau bateau4("Bateau au Bord", make_pair(0, 0), 3);
    cout << "Test du constructeur avec paramètres (cas limite - positions aux limites) : \n" << bateau4 << endl;

    // Nom vide
    CBateau bateau5("", make_pair(10, 10), 2);
    cout << "Test du constructeur avec paramètres (cas limite - nom vide) : \n" << bateau5 << endl;

    // ---- Cas d'erreur ----
    // Taille négative
    // Ce cas n'est pas directement géré par le constructeur, mais l'allocation dynamique de m_pDegats le détectera
    CBateau bateau6("Bateau Invalide", make_pair(3, 3), -2);
    cout << "Test du constructeur avec paramètres (cas d'erreur - taille négative) : \n" << bateau6 << endl;

    // Positions invalides
    // Ce cas n'est pas directement géré par le constructeur, mais l'initialisation de m_positions le détectera
    CBateau bateau7("Bateau Hors Limite", make_pair(100, 100), 4);
    cout << "Test du constructeur avec paramètres (cas d'erreur - positions invalides) : \n" << bateau7 << endl;


	// ### Test du copy-constructeur ###
	// -- Cas normal --
	CBateau bateau8(bateau2);
	cout << "Test du copy-constructeur (cas normal) : \n" << bateau8 << endl;

	// -- Cas limite --
	CBateau bateau9(bateau3);
	cout << "Test du copy-constructeur (cas limite) : \n" << bateau9 << endl;

	// -- Cas d'erreur --
	CBateau bateau10(bateau6);
	cout << "Test du copy-constructeur (cas d'erreur) : \n" << bateau10 << endl;
}


void testAccesseur() {
    // ---- Cas normaux ----
    cout << "Cas Normaux :\n";
    // Création d'un bateau avec des valeurs normales
    CBateau bateauNormal("Porte-avion", make_pair(5, 5), 5);
    cout << "Nom du bateau : " << bateauNormal.getNom() << endl;
    cout << "Taille du bateau : " << bateauNormal.getTaille() << endl;
    pair<int, int> position = bateauNormal.getPosition();
    cout << "Position du bateau : (" << position.first << ", " << position.second << ")\n";
    for (int i = 0; i < bateauNormal.getTaille(); ++i) {
        cout << "Dégâts sur la case " << i << " : " << bateauNormal.getDegats(i) << endl;
    }

    // ---- Cas limites ----
    cout << "\nCas Limites :\n";
    // Création d'un bateau avec des valeurs limites
    CBateau bateauLimite("", make_pair(0, 0), 1);
    cout << "Nom du bateau limite : " << bateauLimite.getNom() << endl;
    cout << "Taille du bateau limite : " << bateauLimite.getTaille() << endl;
    pair<int, int> positionLimite = bateauLimite.getPosition();
    cout << "Position du bateau limite : (" << positionLimite.first << ", " << positionLimite.second << ")\n";
    for (int i = 0; i < bateauLimite.getTaille(); ++i) {
        cout << "Dégâts sur la case " << i << " : " << bateauLimite.getDegats(i) << endl;
    }

    // ---- Cas d'erreur ----
    cout << "\nCas d'Erreur :\n";
    // Création d'un bateau avec des valeurs erronées
    CBateau bateauErreur("Destroyer", make_pair(-1, -1), -5);
    cout << "Nom du bateau en erreur : " << bateauErreur.getNom() << endl;
    cout << "Taille du bateau en erreur : " << bateauErreur.getTaille() << endl;
    pair<int, int> positionErreur = bateauErreur.getPosition();
    cout << "Position du bateau en erreur : (" << positionErreur.first << ", " << positionErreur.second << ")\n";
    for (int i = 0; i < bateauErreur.getTaille(); ++i) {
        cout << "Dégâts sur la case " << i << " : " << bateauErreur.getDegats(i) << endl;
    }
}


void testModificateurs() {
    // ---- Cas normaux ----
    cout << "Cas Normaux :\n";
    // Création d'un bateau avec des valeurs normales
    CBateau bateauNormal("Porte-avion", make_pair(5, 5), 5);
    cout << "Position avant modification : (" << bateauNormal.getPosition().first << ", " << bateauNormal.getPosition().second << ")" << endl;
    // Modification de la position
    bateauNormal.setPosition(3, 4);
    cout << "Position après modification : (" << bateauNormal.getPosition().first << ", " << bateauNormal.getPosition().second << ")\n";

    // ---- Cas limites ----
    cout << "\nCas Limites :\n";
    // Création d'un bateau avec des valeurs limites
    CBateau bateauLimite("", make_pair(0, 0), 1);
    cout << "Position avant modification : (" << bateauLimite.getPosition().first << ", " << bateauLimite.getPosition().second << ")" << endl;
    // Modification de la position
    bateauLimite.setPosition(9, 9); // Position aux limites du jeu
    cout << "Position après modification : (" << bateauLimite.getPosition().first << ", " << bateauLimite.getPosition().second << ")\n";

    // ---- Cas d'erreur ----
    cout << "\nCas d'Erreur :\n";
    // Création d'un bateau avec des valeurs erronées
    CBateau bateauErreur("Destroyer", make_pair(3, 3), 3);
    cout << "Position avant modification : (" << bateauErreur.getPosition().first << ", " << bateauErreur.getPosition().second << ")" << endl;
    // Modification de la position avec des valeurs invalides
    bateauErreur.setPosition(-1, -1); // Position invalide
    cout << "Position après modification : (" << bateauErreur.getPosition().first << ", " << bateauErreur.getPosition().second << ")\n";
}


void testEstCoule() {
    // ---- Cas normaux ----
    cout << "Cas Normaux :\n";
    // Création d'un bateau avec des valeurs normales
    CBateau bateauNormal("Porte-avion", make_pair(5, 5), 5);
    // Aucune case touchée, le bateau ne devrait pas être coulé
    cout << bateauNormal;
    cout << "Le bateau est-il coulé ? " << (bateauNormal.estCoule() ? "Oui\n" : "Non\n") << endl;

    // Toucher toutes les cases sauf une
    for (int i = 0; i < bateauNormal.getTaille() - 1; ++i) {
        // Simuler un tir victorieux sur chaque case
        pair<int, int> tir(bateauNormal.getPosition().first, bateauNormal.getPosition().second + i);
        bateauNormal.tirAdverse(tir);
    }
    // Il reste une case non touchée, le bateau ne devrait pas être coulé
    cout << bateauNormal;
    cout << "Le bateau est-il coulé ? " << (bateauNormal.estCoule() ? "Oui\n" : "Non\n") << endl;

    // Toucher la dernière case
    pair<int, int> tirDerniereCase(bateauNormal.getPosition().first, bateauNormal.getPosition().second + bateauNormal.getTaille() - 1);
    bateauNormal.tirAdverse(tirDerniereCase);
    // Toutes les cases touchées, le bateau devrait être coulé
    cout << bateauNormal;
    cout << "Le bateau est-il coulé ? " << (bateauNormal.estCoule() ? "Oui\n" : "Non\n") << endl;


    // ---- Cas limites ----
    cout << "\nCas Limites :\n";
    // Création d'un bateau avec une seule case
    CBateau bateauLimite("Petit Bateau", make_pair(0, 0), 1);
    // Aucune case touchée, le bateau ne devrait pas être coulé
    cout << bateauLimite;
    cout << "Le bateau est-il coulé ? " << (bateauLimite.estCoule() ? "Oui\n" : "Non\n") << endl;

    // Toucher la seule case
    pair<int, int> tirSeuleCase(bateauLimite.getPosition());
    bateauLimite.tirAdverse(tirSeuleCase);
    // La seule case touchée, le bateau devrait être coulé
    cout << bateauLimite;
    cout << "Le bateau est-il coulé ? " << (bateauLimite.estCoule() ? "Oui\n" : "Non\n") << endl;


    // ---- Cas d'erreur ----
    cout << "\nCas d'Erreur :\n";
    // Création d'un bateau avec des valeurs erronées
    CBateau bateauErreur("Destroyer", make_pair(3, 3), 3);
    // Aucune case touchée, le bateau ne devrait pas être coulé
    cout << bateauErreur;
    cout << "Le bateau est-il coulé ? " << (bateauErreur.estCoule() ? "Oui\n" : "Non\n") << endl;

    // Tentative de toucher une case avec un index invalide
    pair<int, int> tirIndexInvalide(-1, -1); // Tir en dehors des limites du bateau
    bateauErreur.tirAdverse(tirIndexInvalide);
    // Aucune case touchée, le bateau ne devrait pas être coulé
    cout << bateauErreur;
    cout << "Le bateau est-il coulé ? " << (bateauErreur.estCoule() ? "Oui\n" : "Non\n") << endl;
}



void testTirAdverse() {
    // ---- Cas normaux ---- 
    cout << "Cas Normaux :\n";
    // Création d'un bateau avec des valeurs normales
    CBateau bateauNormal("Porte-avion", make_pair(5, 5), 5);
    // Tirer sur une case non touchée mais sur le bateau
    pair<int, int> tirNormal(5, 7);
    cout << "Résultat du tir : " << (bateauNormal.tirAdverse(tirNormal) ? "Touché" : "Manqué") << endl;
    // Tirer sur une case déjà touchée
    cout << "Résultat du tir : " << (bateauNormal.tirAdverse(tirNormal) ? "Touché" : "Manqué") << endl;


    // ---- Cas limites ---- 
    cout << "\nCas Limites :\n";
    // Création d'un bateau avec une seule case
    CBateau bateauLimite("Petit Bateau", make_pair(0, 0), 1);
    // Tirer sur la seule case du bateau
    pair<int, int> tirLimite(0, 0);
    cout << "Résultat du tir : " << (bateauLimite.tirAdverse(tirLimite) ? "Touché" : "Manqué") << endl;


    // ---- Cas d'erreur ---- 
    cout << "\nCas d'Erreur :\n";
    // Création d'un bateau avec des valeurs erronées
    CBateau bateauErreur("Destroyer", make_pair(3, 3), 3);
    // Tirer sur une case qui ne fait pas partie du bateau
    pair<int, int> tirErreur(1, 1);
    cout << "Résultat du tir : " << (bateauErreur.tirAdverse(tirErreur) ? "Touché" : "Manqué") << endl;

    // Tirer sur une case invalide (en dehors des limites de la grille)
    pair<int, int> tirHorsLimite(10, 10);
    cout << "Résultat du tir : " << (bateauErreur.tirAdverse(tirHorsLimite) ? "Touché" : "Manqué") << endl;
}

void testDestructeur() {
    // Création d'un bateau
    CBateau* bateau = new CBateau("Destroyer", make_pair(3, 3), 3);
	cout << "Bateau créé : " << *bateau << endl;

    // Destruction du bateau (appel implicite du destructeur)
    delete bateau;

    // Vérification que le bateau a été détruit en essayant d'accéder à ses attributs (cela devrait générer une erreur)
    cout << "Vérification après destruction :\n";
    cout << "Nom du bateau : " << bateau->getNom() << endl; // Cela devrait générer une erreur de segmentation
    cout << "Taille du bateau : " << bateau->getTaille() << endl; // Cela devrait générer une erreur de segmentation
    pair<int, int> position = bateau->getPosition(); // Cela devrait générer une erreur de segmentation
    cout << "Position du bateau : (" << position.first << ", " << position.second << ")\n"; // Cela devrait générer une erreur de segmentation
}

void testOperator(){
    // Création de deux bateaux
    CBateau bateau1("Porte-avion", make_pair(5, 5), 5);
    CBateau bateau2("Destroyer", make_pair(3, 3), 3);

    // Test de l'opérateur d'affectation
    cout << "Test de l'opérateur d'affectation :\n";
    bateau1 = bateau2;
    cout << "Bateau 1 : " << bateau1 << endl;
    cout << "Bateau 2 : " << bateau2 << endl;
}
