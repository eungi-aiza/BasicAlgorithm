bool    solve(char **board, char *word, int i, int x, int y, int r, int c);

bool    exist(char** board, int boardSize, int* boardColSize, char * word)
{
        if (!board || !boardSize || !boardColSize) return (false);
        if (!word)  return (true);
        for (int i = 0; i < boardSize; i++)
            for (int j = 0; j < boardColSize[0]; j++)
                if (solve(board, word, 0, i, j, boardSize, boardColSize[0]))
                    return (true);
        return (false);
}

bool    solve(char **board, char *word, int i, int x, int y, int r, int c)
{
        bool    found;
        char    temp;

        if (x < 0 || x == r || y < 0 || y == c || word[i] != board[x][y])
		    return (false);
        if (i == strlen(word) - 1)
		    return (true);
        temp = board[x][y];
        board[x][y] = 0;
        found = solve(board, word, i + 1, x + 1, y, r, c) ||
                solve(board, word, i + 1, x - 1, y, r, c) ||
                solve(board, word, i + 1, x, y + 1, r, c) ||
                solve(board, word, i + 1, x, y - 1, r, c);
        board[x][y] = temp;
        return (found);
}