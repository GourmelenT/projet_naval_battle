/*
 * testCGui.cpp
 *
 *  Created on: Feb 10, 2024
 *      Author: tom
 */

#include "CGui.h"

void testConstructeurParDefaut();
void testConstructeurAvecArmadaEtCoups();
void testSetArmadaCoups();
void testPositionnerBateaux();
void testChosirAttaque();
void testAfficheGagne();
void testAffichePerdu();

// Méthode qui exécute tous les tests
int main() {
    // testConstructeurParDefaut();
    // testConstructeurAvecArmadaEtCoups();
    // testSetArmadaCoups();
	// testPositionnerBateaux();
    // testChosirAttaque();
    // testAfficheGagne();
    testAffichePerdu();

    return 0;
}

void testConstructeurParDefaut() {
    cout << "---- Test du constructeur par défaut de CGui ----\n" << endl;

    // Création d'un objet CGui avec le constructeur par défaut
    CGui gui;

    // Vérification que les pointeurs m_pArmada et m_pCoups sont initialisés à nullptr
    cout << "Constructeur initialisé" << endl;
}


void testConstructeurAvecArmadaEtCoups() {
    cout << "---- Test du constructeur avec armada et coups de CGui ----\n" << endl;

    // Création d'un objet CArmada pour les tests
    CArmada* pArmada = new CArmada();
    CCoups* pCoups = new CCoups();

    // Création d'un objet CGui avec le constructeur prenant des pointeurs vers l'armada et les coups
    CGui gui(pArmada, pCoups);

    cout << "Armada et Coups correctement initialisés: \n" << gui << endl;

    // Nettoyage de la mémoire
    delete pArmada;
    delete pCoups;
}


void testSetArmadaCoups() {
    cout << "---- Test de la méthode setArmadaCoups ----\n" << endl;

    // Cas normal : initialisation avec des pointeurs valides
    cout << "Cas normal : initialisation avec des pointeurs valides" << endl;
    CArmada armada;
    CCoups coups;
    CGui gui;
    gui.setArmadaCoups(&armada, &coups);
    cout << "Armada et Coups correctement initialisés." << endl;

    // Cas d'erreur : initialisation avec un pointeur d'armada null
    cout << "\nCas d'erreur : initialisation avec un pointeur d'armada null" << endl;
    CArmada* pArmadaNull = nullptr;
    gui.setArmadaCoups(pArmadaNull, &coups);

    // Cas d'erreur : initialisation avec un pointeur de coups null
    cout << "\nCas d'erreur : initialisation avec un pointeur de coups null" << endl;
    CCoups* pCoupsNull = nullptr;
    gui.setArmadaCoups(&armada, pCoupsNull);
}

void testPositionnerBateaux() {
    cout << "---- Test de la méthode positionnerBateaux ----\n" << endl;

    // Cas normal : positionnement réussi
    cout << "Cas normal : positionnement réussi" << endl;
    CArmada armada;
    
    // Création de bateau
    CBateau bateau1("Porte-avion", make_pair(5, 5), 5);
    CBateau bateau2("Croiseur", make_pair(5, 6), 4);
    CBateau bateau3("Contre-torpilleur", make_pair(5, 7), 3);

    // Ajout des bateaux à l'armada
    armada.ajouterBateau(bateau1);
    armada.ajouterBateau(bateau2);
    armada.ajouterBateau(bateau3);
    
    CCoups coups;
    CGui gui(&armada, &coups);
    bool positionnementReussi = gui.positionnerBateaux();
    if (positionnementReussi) {
        cout << "Positionnement des bateaux réussi." << endl;
    } else {
        cout << "Erreur lors du positionnement des bateaux." << endl;
    }

    // Cas d'erreur : pointeur d'armada null
    cout << "\nCas d'erreur : pointeur d'armada null" << endl;
    CArmada* pArmadaNull = nullptr;
    CGui guiArmadaNull(pArmadaNull, &coups);
    positionnementReussi = guiArmadaNull.positionnerBateaux();
    if (!positionnementReussi) {
        cout << "Erreur attendue : pointeur d'armada null." << endl;
    }

    // Cas d'erreur : pointeur de coups null
    cout << "\nCas d'erreur : pointeur de coups null" << endl;
    CCoups* pCoupsNull = nullptr;
    CGui guiCoupsNull(&armada, pCoupsNull);
    positionnementReussi = guiCoupsNull.positionnerBateaux();
    if (!positionnementReussi) {
        cout << "Erreur attendue : pointeur de coups null." << endl;
    }
}


void testChosirAttaque() {
    cout << "---- Test de la méthode chosirAttaque ----\n" << endl;

    CBateau bateau1("Porte-avion", make_pair(5, 5), 5);
	CBateau bateau2("Croiseur", make_pair(5, 6), 4);
	CBateau bateau3("Contre-torpilleur", make_pair(5, 7), 3);

	CArmada armada;
	// Ajout des bateaux à l'armada
	armada.ajouterBateau(bateau1);
	armada.ajouterBateau(bateau2);
	armada.ajouterBateau(bateau3);

	CCoups coups;
	CGui gui(&armada, &coups);
	bool positionnementReussi = gui.positionnerBateaux();
	if (positionnementReussi) {
		cout << "Positionnement des bateaux réussi." << endl;
		cout << "Cas normal : saisie de coordonnées correctes" << endl;
		pair<int, int> attaque = gui.choisirAttaque();
	} else {
		cout << "Erreur lors du positionnement des bateaux." << endl;
	}

}


void testAfficheGagne() {
    cout << "---- Test de la méthode afficheGagne ----\n" << endl;

    CGui gui;
    gui.afficheGagne();
}

void testAffichePerdu() {
    cout << "---- Test de la méthode affichePerdu ----\n" << endl;

    CGui gui;
    gui.affichePerdu();
}
