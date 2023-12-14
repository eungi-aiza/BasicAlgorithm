
#include <iostream>
#include <vector>
using namespace std;
//Traverse over every unit and check if it is land, perimeter +=4
// And if there is a land above it, perimeter -= 2, same for left side land.
// Return the ans.

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int ans=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1){
                    // check for i-1,j and i,j-1
                    ans+=4;
                    if(i>0 && grid[i-1][j]==1) ans-=2;
                    if(j>0 && grid[i][j-1]==1) ans-=2;
                }
            }
       }
       return ans; 
    }
};