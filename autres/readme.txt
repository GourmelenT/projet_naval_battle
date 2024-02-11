| - Rapport sur l'état d'avancement du projet - |

| État d'avancement actuel :

Le projet de jeu de la bataille navale est terminé.

Pour lancer le jeu il suffit de se rendre dossiers autres et ouvrir un terminal :

Indiquer la commande " make play " pour lancer le jeu. Vous devriez donc voir apparaître : 
____________________________________________________________

<votre_environnement>\ProjetNavalBattle\autres> make play
____________________________________________________________

!! Attention !! -> Pour commencer une partie il faudra obligatoirement ouvrir le serveur en premier en tapant 0.
Dans la deuxième interface vous devrez donc indiqué 1 pour le client et à vous de jouer.

| Classes existantes :

1. **CBateau** : Représente un bateau dans le jeu de la bataille navale.
2. **CArmada** : Représente une armada de bateaux dans le jeu de la bataille navale.
3. **CGui** : Permet de jouer à la bataille navale en mode graphique.

| Fonctionnalités implémentées :

- Lecture de la configuration de l'armada à partir d'un fichier texte.
- Placement aléatoire des bateaux sur la grille.
- Affichage des grilles pour le joueur et l'adversaire.
- Saisie de coordonnées pour une attaque.
- + Confirmation de l'attaque
- Affichage des messages de victoire et de défaite.

| Classes compilables et testables :

Les classes suivantes peuvent être compilées et testées :

Toutes les classes que nous avons dû créer ont une méthode de test assigné. 

- **CBateau** : Testable en créant des objets CBateau et en vérifiant les méthodes de positionnement et d'état.
- **CArmada** : Peut être testée en créant une armada de bateaux et en vérifiant le placement aléatoire des bateaux.
- **CGui** : Bien qu'elle soit destinée à l'interface graphique, les fonctionnalités de base peuvent être testées via des tests unitaires.