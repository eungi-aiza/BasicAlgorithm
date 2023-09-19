// Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

// Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
// Output: 2
// Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.

// Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
// Output: 4
// Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        const int n = grid.size();
        
        queue<pair<int, int>> lands;
        vector<vector<int>> visited (n, vector<int>(n, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                
                if (grid[i][j]) {
                    lands.push({i, j});
                    
                    visited[i][j] = 1;
                }
            }
        }
        
        if (lands.size() == 0 || lands.size() == n*n)
            return -1;
        
        int dist = 0;
        
        for (;;) {
            
            int size = lands.size();
            
            for (int i = 0; i < size; ++i) {
                
                auto [row, col] = lands.front();
                
                lands.pop();
                
                add_node(row-1, col, n, lands, visited);
                add_node(row+1, col, n, lands, visited);
                add_node(row, col-1, n, lands, visited);
                add_node(row, col+1, n, lands, visited);
            }
            
            if (lands.empty()) 
                break;
            else
                dist++;
        }
        return dist;
    }
    
    
    void add_node(int row, int col, int n, queue<pair<int, int>> &lands, vector<vector<int>> &visited) {
        
        if (row < 0 || row >= n || col < 0 || col >= n)
            return;
        
        if (visited[row][col])
            return;
        
        visited[row][col] = 1;
        
        lands.push({row, col});
    }
};



