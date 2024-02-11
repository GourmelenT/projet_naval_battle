/*
 * CBateau.h
 *
 *  Created on: Jan 30, 2024
 *      Author: tom
 */

#ifndef SRC_CBATEAU_H_
#define SRC_CBATEAU_H_

#include "BiblioStd.h"

/**
 * @class CBateau
 * 
 * Description :
 *  Un bateau et caractérisé par le nombre de cases qu'il occupe sur la grille, par un nom (porte-avion, croiseur...)
 *  et par le point de départ de sa position horizontale sur la grillr (point d'ancrage).
 *
 *  Il mémorise également dans un tableau de booléans les dégâts occasionnés sur le bateau
 */
class CBateau {
	// Attributs
	private:
		/**
		 * Nombre de cases occupées sur la grille par des bateaux.
		 */
		int m_taille;

		/**
		 * Nom du bateau.
		 */
		string m_nom;

		/**
		 * Coordonnées du point d'ancrage.
		 *
		 * - m_position.first : le numéro de la ligne horizontale.
		 * - m_position.second : le numéro de la colonne verticale.
		 */
		pair<int, int> m_positions;

		/**
		 * Tableau des dégâts de taille m_taille.
		 *
		 * Case à faux si pas de dégât.
		 */
		bool* m_pDegats;

	// Méthodes
	public:
		/**
		 * Constructeur par défaut.
		 *
		 * Initialise avec "néant", (0,0), 0, NULL.
		 */
		CBateau();

		/**
		 * Constructeur.
		 *
		 * Le bateau n'a encore aucune case touchée, m_pDegats à faux partout.
		 * @param n Nom du bateau.
		 * @param p Position d'ancrage du bateau.
		 * @param t Taille du bateau.
		 */
		CBateau(string n, pair<int,int> p, int t);

		/**
		 * Copy-constructeur permettant de copier notre liste par référence.
		 *
		 * @param positionToCopy CBateau à copier.
		 */
		CBateau(const CBateau& positionToCopy);

		/**
		 * Renvoie vrai si la case numéro i du bateau est touchée.
		 *
		 * @param i Index de la case (0 <= i <  m_taille).
		 * @return bool - Faux si aucune case du bateau n'a été touchée.
		 */
		bool getDegats(int i);

		/**
		 * Accesseur pour le nom du bateau.
		 * @return Nom du bateau.
		 */
		string getNom();

		/**
		 * Accesseur pour la taille du bateau.
		 * @return Taille du bateau.
		 */
		int getTaille();

		/**
		 * Accesseur pour la position d'ancrage du bateau.
		 * @return Tableau de position <ligne, colonne> du bateau.
		 */
		pair <int,int> getPosition();

		/**
		 * Modifie la position du bateau sur la grille en ième ligne, jième colonne.
		 *
		 * @param i Nouvelle ligne d'ancrage.
		 * @param j Nouvelle colonne d'ancrage.
		 */
		void setPosition(int i, int j);

		/**
		 * Renvoie vrai si le bateau est coulé.
		 * @return Bool - Faux si le bateau n'est pas encore coulé.
		 */
		bool estCoule();

		/**
		 * Tir adverse : renvoie vrai si la coordonnée passée en paramètre est un tir victorieux
		 * (une case du bateau est touchée). Si le tir est victorieux, il doit être marqué dans le tableau m_pDegats.
		 * ATTENTION : si une case est déjà touchée, il ne faut PAS renvoyer vrai (donc renvoyer faux),
		 * sinon un tir victorieux est comptabilisé en trop.
		 *
		 * @param p Coordonnées du tir adverse.
		 * @return True si le tir adverse est victorieux, sinon False.
		 */
		bool tirAdverse(pair<int, int> p);

		/**
		 * Surcharge de l'opérateur << pour afficher à l'écran les caractéristiques du bateau.
		 *
		 * @param os Flux de sortie.
		 * @param theB Bateau à afficher.
		 * @return Flux de sortie mis à jour.
		 */
		friend ostream& operator << (ostream& os, CBateau& theB);

		/**
		 * Affectation d'objets.
		 *
		 * On surcharge l'opérateur '='.
		 * @param positionToCopy L'objet à copier par référence.
		 */
		void operator= (const CBateau& positionToCopy);

		/**
		 * Destructeur.
		 *
		 * Libère la mémoire allouée pour le tableau des dégâts.
		 */
		~CBateau();
};

#endif /* SRC_CBATEAU_H_ */
