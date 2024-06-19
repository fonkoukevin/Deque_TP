TP_deque
Groupe:

Fonkou Mukeme Kevin

Gassam Gassam Lionel junior



Utilisations de deque et Recherche de Chemin

Ce projet implémente un générateur de grille aléatoire et un algorithme de recherche de chemin pour trouver un chemin de (0, 0) à (taille-1, taille-1) si possible.

## Fonctionnalités

1. **Génération de Grille** :
   - La classe `Grid` génère une grille de taille spécifiée avec des cellules passables et impassables selon une probabilité définie.
   - La grille est affichée avec les cellules passables marquées par `[ ]` et les impassables par `[X]`.
   - Les points de départ (0, 0) et de fin (taille-1, taille-1) sont toujours passables.

2. **Recherche de Chemin** :
   - La classe `PathFinder` utilise une recherche en largeur (BFS) pour trouver un chemin de (0, 0) à (taille-1, taille-1).
   - Si un chemin est trouvé, il est affiché sur la grille avec les points du chemin marqués par `[*]`.

## Utilisation

1. **Initialisation** :
   - Demande à l'utilisateur de saisir la taille de la grille.
   - Crée une grille avec une probabilité de cellules passables de 70%.

2. **Affichage de la Grille** :
   - Affiche la grille générée aléatoirement.

3. **Recherche de Chemin** :
   - Recherche un chemin de (0, 0) à (taille-1, taille-1).
   - Si un chemin est trouvé, affiche la grille avec le chemin et les coordonnées des points traversés.

## Classes

- **Point** : Structure représentant un point sur la grille avec des coordonnées x et y.
- **Grid** : Classe pour générer et gérer la grille.
  - `initializeGrid()` : Initialise la grille avec des cellules passables et impassables.
  - `displayGrid()` : Affiche la grille.
  - `displayGridWithPath(const vector<Point>& chemin)` : Affiche la grille avec un chemin.
  - `isCellPassable(int x, int y)` : Vérifie si une cellule est passable.
- **PathFinder** : Classe pour trouver un chemin sur la grille.
  - `isValid(int x, int y)` : Vérifie si une cellule est valide pour le déplacement.
  - `findPath(vector<Point>& path)` : Trouve un chemin de (0, 0) à (taille-1, taille-1) et le stocke dans `path`.

## Conclusion

Ce projet démontre comment générer une grille aléatoire et utiliser un algorithme de recherche en largeur pour trouver un chemin à travers cette grille.
