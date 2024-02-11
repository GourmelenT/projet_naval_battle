/*
 * CArmada.h
 *
 *  Created on: Jan 31, 2024
 *      Author: tom
 */

#ifndef SRC_CARMADA_H_
#define SRC_CARMADA_H_

#include "BiblioStd.h"
#include "CBateau.h"

/**
 * @class CArmada
 * Représente une armada de bateaux dans le jeu de la bataille navale.
 *
 * Cette classe gère la collection de bateaux, leur ajout, la lecture à partir d'un fichier,
 * et le placement aléatoire sur la grille de jeu.
 */
class CArmada {
    // Attributs
    private:

        /**
         * Collection de bateaux.
         */
        std::vector<CBateau> m_listeBateaux; 

    // Méthodes
    public:
        /**
         * Constructeur par défaut.
         */
        CArmada();

        /**
         * Ajoute un bateau à la collection.
         * 
         * @param unBat Référence vers le bateau à ajouter.
         */
        void ajouterBateau(CBateau& unBat);

        /**
         * Renvoie un pointeur vers le bateau à l'index spécifié.
         * 
         * @param i Index du bateau dans la collection (0 <= i < taille).
         * 
         * @return Pointeur vers le bateau ou nullptr si l'index est invalide.
         */
        CBateau* getBateau(int i);

        /**
         * Renvoie le nombre total de bateaux dans l'armada.
         * 
         * @return Nombre total de bateaux.
         */
        int getEffectifTotal();

        /**
         * Renvoie le nombre total de cases occupées par l'armada.
         * 
         * @return Nombre total de cases occupées.
         */
        int getNbreTotCases();

        /**
         * Renvoie le nombre de bateaux non coulés dans l'armada.
         * 
         * @return Nombre de bateaux non coulés.
         */
        int getEffectif();

        /**
         * Lit la configuration de l'armada à partir d'un fichier texte.
         */
        void getArmadaFromFile();

        /**
         * Place aléatoirement tous les bateaux sur la grille.
         * 
         * @return True si le placement automatique a réussi, sinon False.
         */
        bool placerAleatoirement();

        /**
		 * Copy-constructeur permettant de copier notre liste par référence.
		 *
		 * @param listToCopy CArmada à copier.
		 */
        CArmada(const CArmada& listToCopy);
};

#endif /* SRC_CARMADA_H_ */
