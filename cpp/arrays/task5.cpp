#include <iostream>
using namespace std;

const int GRID_SIZE = 10;

bool hasAdjacentValue(int grid[GRID_SIZE][GRID_SIZE], int r, int c, int target) {
    if (grid[r][c] == target) return true;
    return false;
}

bool checkNeighbors(int grid[GRID_SIZE][GRID_SIZE], int r, int c, int val) {
    bool found = false;
    
    // Check all 8 directions with boundary checks
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) continue;
            
            int nr = r + dr;
            int nc = c + dc;
            
            if (nr >= 0 && nr < GRID_SIZE && nc >= 0 && nc < GRID_SIZE) {
                if (hasAdjacentValue(grid, nr, nc, val + 1)) {
                    found = true;
                }
            }
        }
    }
    return found;
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE] = { 
        {1,1,0,0,0,0,0,0,1,1},
        {1,1,1,1,1,0,0,1,1,1},
        {0,1,1,1,1,0,0,1,1,0},
        {0,0,0,0,0,0,0,0,1,0},
        {0,0,1,1,1,1,1,0,0,0},
        {0,0,1,1,1,1,1,0,1,0},
        {0,0,1,1,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,0,0,0,0,0,1},
        {1,1,1,1,0,0,0,0,1,1} 
    };
    
    int polygonCount = 0;
    
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 1) {
                polygonCount++;
                grid[i][j] = polygonCount + 1;

                for (int k = 0; k < GRID_SIZE; k++) {
                    for (int p = 0; p < GRID_SIZE; p++) {
                        if (checkNeighbors(grid, k, p, polygonCount) && grid[k][p] == 1) {
                            grid[k][p] = polygonCount + 1;
                        }
                    }
                }
            }
        }
    }
    
    cout << "Processed Grid:" << endl;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "Total polygons: " << polygonCount << endl;
    
    return 0;
}
