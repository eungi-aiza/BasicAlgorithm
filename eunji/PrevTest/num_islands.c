#include <stdio.h>
#include <stdbool.h>

// Define the dimensions of the grid
#define ROWS 4
#define COLS 5

// Define the directions for DFS
int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// Function to perform DFS traversal and mark an island as visited
void dfs(char grid[ROWS][COLS], int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || grid[row][col] != '1') {
        return; // Invalid position or not land
    }

    grid[row][col] = '0'; // Mark the current cell as visited

    // Recursively visit all adjacent land cells
    for (int i = 0; i < 4; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];
        dfs(grid, newRow, newCol);
    }
}

// Function to count the number of islands
int numIslands(char grid[ROWS][COLS]) {
    int count = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }

    return count;
}

int main() {
    char grid[ROWS][COLS] = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    int islands = numIslands(grid);
    printf("Number of Islands: %d\n", islands);

    return 0;
}
