/*
 * CGui.h
 *
 *  Created on: Jan 31, 2024
 *      Author: tom
 */

#ifndef CGUI_H
#define CGUI_H

#include "BiblioStd.h"
#include "CBaseJeu.h"
#include "CArmada.h"
#include "CCoups.h"

/**
 * Classe CGui
 *
 * Cette classe permet de jouer à la bataille navale en mode graphique.
 * Elle hérite de CBaseJeu.
 *
 */
class CGui : public CBaseJeu {
    // Attributs
    private :
        /**
         * Grille du joueur
         */
        char m_grilleJou[TAILLE_GRILLE-1][TAILLE_GRILLE-1];

        /**
         * Grille de l'adversaire
         */
        char m_grilleAdv[TAILLE_GRILLE-1][TAILLE_GRILLE-1];

        /**
         * Pointeur sur l'armada du joueur
         */
        CArmada* m_pArmada;

        /**
         * Pointeur sur les données des coups joués
         */
        CCoups* m_pCoups;

    // Méthodes publiques
    public:

        /**
         * Constructeur par défaut, même s'il n'est pas demandé j'ai quand même décider d'agir dessus
         *
         * m_pArmada et m_pCoups sont initialisés à nullptr
         */
        CGui();

        /**
         * Constructeur qui reçoit un pointeur vers l'armada et un
         * pointeur sur la structure d'enregistrement des coups
         *
         * @param pArmada : pointeur vers l'armada
         * @param pCoups : pointeur vers les coups
         */
        CGui(CArmada* pArmada, CCoups* pCoups);

        /**
         * Destructeur
         *
         * Destruction des zones pointées par m_pArmada et m_pCoups
         */
        virtual ~CGui();

        /**
         * Modificateur : Mise à jour des attributs m_pArmada et m_pCoups
         *
         * @param pArmada : pointeur vers l'armada
         * @param pCoups : pointeur vers les coups
         */
        void setArmadaCoups(CArmada* pArmada, CCoups* pCoups);

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
        friend ostream& operator<<(ostream& os, CGui& theG);

        /**
         * Méthode appelée au début du jeu pour positionner tous les bateaux
         * sur la grille en éxécutant placeAleatoirement() de CArmada
         *
         * @return false si le positionnement a échoué
         */
        bool positionnerBateaux();

        /**
         * Saisie de la coordonnée (ligne, colonne) de l'attaque (vérfication
         * ogligatoire bon/mauvais après saisie de la coordonnée par l'utilisateur)
         *
         * @return la coordonnée de l'attaque
         */
        pair<int,int> choisirAttaque ();

        /**
         * Affiche la partie est gagnée à l'écran
         */
        void afficheGagne();

        /**
         * Affiche la partie est perdue à l'écran
         */
        void affichePerdu();

    // Méthodes privées
    private :

        /**
         * Remplissage des deux grilles (la grille de l'attaquant et la grille
         * de l'adversaire) avec les bateaux et les coups joués
         *
         * @param os : le flux de sortie
         */
        void remplirDeuxGrilles(ostream& os);

        /**
         * Affichage d'une grille (joueur ou adversaire) à l'écran,
         * c'est-à-dire affichage du contenu de m_grilleJou ou
         * m_grilleAdv + les légendes (0...TAILLE_GRILLE-2).
         *
         * @param os : le flux de sortie
         * @param jouOuAdv : "joueur" ou "adversaire"
         */
        void afficherLaGrille(ostream& os, string jouOuAdv);
};




#endif /* SRC_CGUI_H_ */
