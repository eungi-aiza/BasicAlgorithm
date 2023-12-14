class Solution {
public:
bool matrixFound = false;
    bool canPut (int x, int i, int j, vector<vector<char>> &board) {
        for (int v=0; v<9; v++) {
            if (board[i][v] == x+'0') return false;
            if (board[v][j] == x+'0') return false;
        }

        for (int a = i/3 * 3; a<(i/3*3 + 3); a++) {
            for ( int b = j/3 * 3 ; b<(j/3*3 + 3); b++) {
                if (board[a][b] == x+'0') return false;
            }
        }
        return true;
    }
    void solve (vector<vector<char>>& board, int i, int j) {
        if (matrixFound) return;
        if (i==9) {
            matrixFound = true;
            return;
        }
        if (j==9) {
            solve(board, i+1, 0);
        }
        else {
            if (board[i][j] != '.') {
                solve(board, i, j+1);
        if (matrixFound) return;
            }
            else {
                for (int x=1; x<=9; x++) {
                    if (canPut(x, i, j, board)) {
                        board[i][j] = x+'0';
                        solve(board, i, j+1);
        if (matrixFound) return;
                        board[i][j] = '.';
                    }
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};

// class Solution {
// public:
// bool matrixFound = false;
//     bool canPut (int x, int i, int j, vector<vector<char>> &board) {
//         for (int v=0; v<9; v++) {
//             if (board[i][v] == x+'0') return false;
//             if (board[v][j] == x+'0') return false;
//         }

//         for (int a = i/3 * 3; a<(i/3*3 + 3); a++) {
//             for ( int b = j/3 * 3 ; b<(j/3*3 + 3); b++) {
//                 if (board[a][b] == x+'0') return false;
//             }
//         }
//         return true;
//     }
//     void solve (vector<vector<char>>& board, int i, int j) {
//         if (matrixFound) return;
//         if (i==9) {
//             matrixFound = true;
//             return;
//         }
//         if (j==9) {
//             solve(board, i+1, 0);
//         }
//         else {
//             if (board[i][j] != '.') {
//                 solve(board, i, j+1);
//         if (matrixFound) return;
//             }
//             else {
//                 for (int x=1; x<=9; x++) {
//                     if (canPut(x, i, j, board)) {
//                         board[i][j] = x+'0';
//                         solve(board, i, j+1);
//         if (matrixFound) return;
//                         board[i][j] = '.';
//                     }
//                 }
//             }
//         }
//     }
//     void solveSudoku(vector<vector<char>>& board) {
//         solve(board, 0, 0);
//     }
// };