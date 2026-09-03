#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <string>

using namespace std;

int main() {
    int rows;
    int columns;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;

    int** map = new int*[rows];

    for (int i = 0; i < rows; ++i) {
        map[i] = new int[columns];
    }

    srand(time(0));

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            map[r][c] = rand() % 5;
        }
    }

    cout << "\n--- Map Legend ---" << endl;
    cout << "0: Grass | 1: Water | 2: Mountain | 3: Forest | 4: Dungeon\n" << endl;

    cout << "--- Generated Map (" << rows << "x" << columns << ") ---" << endl;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            cout << map[r][c] << " ";
        }
        cout << endl; 
    }

    int tileCounts[5] = {0};
    string tileNames[5] = {"Grass", "Water", "Mountain", "Forest", "Dungeon"};

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            int tileType = map[r][c];
            tileCounts[tileType]++;
        }
    }

    cout << "\n--- Tile Counts ---" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << tileNames[i] << " (" << i << "): " << tileCounts[i] << endl;
    }


    for (int i = 0; i < rows; ++i) {
        delete[] map[i];
    }


    delete[] map;


    map = nullptr;

    return 0;
}