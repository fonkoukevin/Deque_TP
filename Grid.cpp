//
// Created by Fonkou kevin on 18/06/2024.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <algorithm>


using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};


class Grid {
private:
    vector<vector<bool>> grid;
    int size;
    double passableProbability;

public:
    Grid(int _size, double _passableProbability)
            : size(_size), passableProbability(_passableProbability) {
        initializeGrid();
    }

    void initializeGrid() {
        grid.resize(size, vector<bool>(size, false));
        srand(time(nullptr));

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                double randValue = static_cast<double>(rand()) / RAND_MAX;
                grid[i][j] = randValue < passableProbability;
            }
        }

        grid[0][0] = true; // Début toujours passable
        grid[size - 1][size - 1] = true; // Fin toujours passable
    }

    void displayGrid() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (grid[i][j]) {
                    cout << "[ ] "; // Case passable
                } else {
                    cout << "[X] "; // Case impassable
                }
            }
            cout << endl;
        }
    }

    void displayGridWithPath(const vector<Point>& chemin) const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i == 0 && j == 0) {
                    cout << "[Debut] ";
                } else if (i == size - 1 && j == size - 1) {
                    cout << "[Fin] ";
                } else if (grid[i][j]) {
                    bool inPath = false;
                    for (const auto& point : chemin) {
                        if (point.x == i && point.y == j) {
                            inPath = true;
                            break;
                        }
                    }
                    if (inPath) {
                        cout << "[*] ";
                    } else {
                        cout << "[ ] ";
                    }
                } else {
                    cout << "[X] ";
                }
            }
            cout << endl;
        }
    }

    bool isCellPassable(int x, int y) const {
        if (x < 0 || x >= size || y < 0 || y >= size) {
            return false;
        }
        return grid[x][y];
    }

    int getSize() const {
        return size;
    }

    const vector<vector<bool>>& getGrid() const {
        return grid;
    }
};



class PathFinder {
private:
    const Grid& grid;
    vector<vector<bool>> visited;
    vector<vector<Point>> parent;
    vector<Point> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Haut, Bas, Gauche, Droite

public:
    PathFinder(const Grid& _grid) : grid(_grid) {
        visited.resize(grid.getSize(), vector<bool>(grid.getSize(), false));
        parent.resize(grid.getSize(), vector<Point>(grid.getSize(), Point(-1, -1)));
    }

    bool isValid(int x, int y) const {
        int size = grid.getSize();
        return (x >= 0 && x < size && y >= 0 && y < size && grid.isCellPassable(x, y) && !visited[x][y]);
    }

    bool findPath(vector<Point>& path) {
        int size = grid.getSize();
        if (!grid.isCellPassable(0, 0) || !grid.isCellPassable(size - 1, size - 1)) {
            cout << "Le point de depart ou d'arrivee n'est pas passable." << endl;
            return false;
        }

        queue<Point> q;
        q.push(Point(0, 0));
        visited[0][0] = true;

        while (!q.empty()) {
            Point current = q.front();
            q.pop();

            if (current.x == size - 1 && current.y == size - 1) {

                Point pathPoint = current;
                while (pathPoint.x != -1 && pathPoint.y != -1) {
                    path.push_back(pathPoint);
                    pathPoint = parent[pathPoint.x][pathPoint.y];
                }
                reverse(path.begin(), path.end());
                return true;
            }

            for (const auto& dir : directions) {
                int nx = current.x + dir.x;
                int ny = current.y + dir.y;
                if (isValid(nx, ny)) {
                    q.push(Point(nx, ny));
                    visited[nx][ny] = true;
                    parent[nx][ny] = current;
                }
            }
        }

        return false;
    }
};