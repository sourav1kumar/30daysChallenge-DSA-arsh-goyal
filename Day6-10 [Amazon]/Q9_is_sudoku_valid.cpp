/*
Given an incomplete Sudoku configuration in terms of a 9x9  2-D square matrix(mat[][]) the task to check if the current configuration is valid or not where a 0 represents an empty block.
*/

class Solution
{
public:
    bool check(vector<vector<int>> mat, int row, int col)
    {
        for (int i = 0; i < 9; ++i)
            if (i != col && mat[row][i] == mat[row][col])
            {
                return true;
            }

        for (int i = 0; i < 9; ++i)
            if (i != row && mat[i][col] == mat[row][col])
            {
                return true;
            }

        for (int i = 0; i < 9; ++i)
        {
            int r1 = 3 * (row / 3) + i / 3, c1 = 3 * (col / 3) + i % 3;
            if ((r1 != row || c1 != col) && mat[r1][c1] == mat[row][col])
            {
                return true;
            }
        }

        return false;
    }

    int isValid(vector<vector<int>> mat)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (mat[i][j] == 0)
                    continue;
                if (check(mat, i, j))
                    return 0;
            }
        }
        return 1;
    }
};