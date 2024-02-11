/*
 * testCArmada.cpp
 *
 *  Created on: Fev 06, 2024
 *      Author: tom
 */

#include "CArmada.h"

void testConstructeurParDefaut();
void testAjouterBateau();
void testGetBateau();
void testGetEffectifTotal();
void testGetNbreTotCases();
void testGetEffectif();
void testGetArmadaFromFile();
void testPlacerAleatoirement();
void testDestructionArmada();


// Méthode qui exécute tous les tests
int main() {
    testConstructeurParDefaut();
    // testAjouterBateau();
    // testGetBateau();
    // testGetEffectifTotal();
    // testGetNbreTotCases();
    // testGetEffectif();
    // testGetArmadaFromFile();
    // testPlacerAleatoirement();
    // testDestructionArmada();

    return 0;
}

void testConstructeurParDefaut() {
    cout << "---- Test du constructeur par défaut de CArmada ----\n" << endl;
    CArmada armada;
    cout << "Effectif total attendu : 0 -> Obtenu : " << armada.getEffectifTotal() << endl;
    cout << "Nombre total de cases occupées attendu : 0 -> Obtenu : " << armada.getNbreTotCases() << endl;
    cout << "Nombre d'effectif attendu : 0 -> Obtenu : " << armada.getEffectif() << endl;
}

void testAjouterBateau() {
    // Cas normaux
    cout << "Cas Normaux : " << endl;
    CArmada armada;
    CBateau bateau1("Porte-avion", make_pair(5, 5), 5);
    armada.ajouterBateau(bateau1);
    cout << "Effectif total après ajout : " << armada.getEffectifTotal() << endl;

    // Cas limite - ajout d'un bateau déjà existant
    cout << "Cas Limite - Ajout d'un bateau déjà existant : " << endl;
    armada.ajouterBateau(bateau1); // Ajout du même bateau
    cout << "Effectif total après ajout : " << armada.getEffectifTotal() << endl;

    // Cas d'erreur - ajout d'un bateau non correctement défini
    cout << "Cas d'Erreur - Ajout d'un bateau non correctement défini : " << endl;
    CBateau bateauErr("néant", make_pair(0, 0), 0);
    armada.ajouterBateau(bateauErr); // Ajout d'un bateau non correctement défini
}

void testGetBateau() {
    // Cas normaux
    cout << "Cas Normaux : " << endl;
    CArmada armada;
    CBateau bateau1("Porte-avion", make_pair(5, 5), 5);
    armada.ajouterBateau(bateau1);
    CBateau* ptrBateau = armada.getBateau(0);
    if (ptrBateau != nullptr) {
        cout << "Nom du bateau récupéré : " << ptrBateau->getNom() << endl;
    }

    // Cas limite - index invalide
    cout << "Cas Limite - Index invalide : " << endl;
    CBateau* ptrBateauLim = armada.getBateau(1); // Index invalide
    if (ptrBateauLim == nullptr) {
        cout << "Pointeur nul retourné pour index invalide." << endl;
    }
}

void testGetEffectifTotal() {
    // Cas normal
    cout << "Cas Normaux : " << endl;
    CArmada armada;
    CBateau bateau1("Porte-avion", make_pair(5, 5), 5);
    armada.ajouterBateau(bateau1);
    cout << "Effectif total : " << armada.getEffectifTotal() << endl;

    // Cas limite - aucun bateau ajouté
    cout << "Cas Limite - Aucun bateau ajouté : " << endl;
    CArmada armadaVide;
    cout << "Effectif total : " << armadaVide.getEffectifTotal() << endl;
}

void testGetNbreTotCases() {
    // Cas normal
    cout << "Cas Normaux : " << endl;
    CArmada armada;
    CBateau bateau1("Porte-avion", make_pair(5, 5), 5);
    armada.ajouterBateau(bateau1);
    cout << "Nombre total de cases occupées : " << armada.getNbreTotCases() << endl;

    // Cas limite - aucun bateau ajouté
    cout << "Cas Limite - Aucun bateau ajouté : " << endl;
    CArmada armadaVide;
    cout << "Nombre total de cases occupées : " << armadaVide.getNbreTotCases() << endl;
}

void testGetEffectif() {
    // Cas normal
    cout << "Cas Normaux : " << endl;
    CArmada armada;
    CBateau bateau1("Porte-avion", make_pair(5, 5), 5);
    armada.ajouterBateau(bateau1);
    cout << "Effectif de bateaux non coulés : " << armada.getEffectif() << endl;

    // Cas limite - tous les bateaux coulés
    cout << "\nCas Limite - Tous les bateaux coulés : " << endl;
    CArmada armadaTousCoulés;
    CBateau bateau2("Destroyer", make_pair(3, 3), 3);
    armadaTousCoulés.ajouterBateau(bateau2);

    // Toucher toutes les cases pour couler le bateau
    CBateau* pt_bateau2 = armadaTousCoulés.getBateau(0);
    for (int i = 0; i < bateau2.getTaille(); ++i) {
		// Simuler un tir victorieux sur chaque case
		pair<int, int> tir(bateau2.getPosition().first, bateau2.getPosition().second + i);
		pt_bateau2->tirAdverse(tir);
	}

    cout << "Effectif de bateaux non coulés : " << armadaTousCoulés.getEffectif() << endl;

    // Cas d'erreurs - Aucun bateau dans l'armada
    cout << "\nCas Erreur - Aucun bateau dans l'armada : " << endl;
    CArmada armadaVide;
    cout << "Effectif de bateaux non coulés : " << armadaVide.getEffectif() << endl;
}

void testGetArmadaFromFile() {
    // Cas normal - fichier flotille.txt correct
    cout << "Cas Normaux - Fichier flotille.txt correct : " << endl;
    CArmada armada;
    armada.getArmadaFromFile();
    cout << "Effectif total après lecture du fichier : " << armada.getEffectifTotal() << endl;

    // Cas d'erreur - fichier flotille.txt absent
    cout << "\nCas d'Erreur - Fichier flotille.txt absent : " << endl;
    CArmada armadaErreur;
    armadaErreur.getArmadaFromFile();
}

void testPlacerAleatoirement() {
    // Cas normal
    cout << "Cas Normaux : " << endl;
    CArmada armada;
    CBateau bateau1("Porte-avion", make_pair(5, 5), 5);
    armada.ajouterBateau(bateau1);
    cout << "Placement aléatoire réussi ? " << (armada.placerAleatoirement() ? "Oui" : "Non") << endl;

    // Cas limite - aucun bateau à placer
    cout << "\nCas Limite - Aucun bateau à placer : " << endl;
    CArmada armadaVide;
    cout << "Placement aléatoire réussi ? " << (armadaVide.placerAleatoirement() ? "Oui" : "Non") << endl;
}

void testDestructionArmada() {
    // Création d'une armada
    CArmada* armada = new CArmada();
    CBateau bateau1("Porte-avion", make_pair(5, 5), 5);
    armada->ajouterBateau(bateau1);
    cout << "Armada créée avec un bateau : " << endl;
    cout << "Effectif total : " << armada->getEffectifTotal() << endl;

    // Destruction de l'armada (appel implicite du destructeur)
    delete armada;

    // Vérification que l'armada a été détruite en essayant d'accéder à ses attributs (cela devrait générer une erreur)
    cout << "Vérification après destruction de l'armada : " << endl;
    cout << "Effectif total : " << armada->getEffectifTotal() << endl; // Cela devrait générer une erreur de segmentation
}
