#include <iostream>
#include <vector>
#include "Grid.cpp"


using namespace std;



int main() {
    int tailleGrille;
    cout << "Entrez la taille de la grille : ";
    cin >> tailleGrille;

    const double probabilitePassable = 0.7;

    Grid grid(tailleGrille, probabilitePassable);

    cout << "Grille generee aleatoirement :" << endl;
    grid.displayGrid();

    PathFinder pathFinder(grid);
    vector<Point> chemin;

    if (pathFinder.findPath(chemin)) {
        cout << endl << "Chemin trouve :" << endl;
        grid.displayGridWithPath(chemin);
        cout << endl << "Points traverses :" << endl;
        for (const auto& point : chemin) {
            cout << "(" << point.x << ", " << point.y << ") ";
        }
        cout << endl;
    } else {
        cout << "Aucun chemin trouve." << endl;
    }

    return 0;
}
