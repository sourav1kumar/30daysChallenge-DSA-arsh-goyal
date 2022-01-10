/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

*/

class Solution
{
public:
    int n, m, dp[12][12];
    void dfs(vector<vector<int>> &grid, int i, int j, int count)
    {

        if (i < 0 || j < 0 || i == n || j == m || grid[i][j] == 0 || dp[i][j] < count)
            return;
        dp[i][j] = min(dp[i][j], count);
        dfs(grid, i + 1, j, count + 1);
        dfs(grid, i - 1, j, count + 1);
        dfs(grid, i, j + 1, count + 1);
        dfs(grid, i, j - 1, count + 1);
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < 12; ++i)
            for (int j = 0; j < 12; ++j)
                dp[i][j] = 100;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 2)
                    dfs(grid, i, j, 0);
            }
        }

        int maxtime = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                    maxtime = max(maxtime, dp[i][j]);
            }
        }
        if (maxtime == 100)
            return -1;
        return maxtime;
    }
};