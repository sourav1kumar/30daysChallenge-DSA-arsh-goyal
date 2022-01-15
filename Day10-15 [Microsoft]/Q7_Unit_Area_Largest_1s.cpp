/*
Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).
*/
class Solution
{
public:
    int n, m;
    int dfs(vector<vector<int>> & grid, int i, int j, vector<vector<int>> &vis)
    {
        if (i < 0 || j < 0 || i == n || j == m || grid[i][j] == 0 || vis[i][j] == 1)
            return 0;
        vis[i][j] = 1;
        int ans = 1;
        for (int dx = -1; dx <= 1; ++dx)
            for (int dy = -1; dy <= 1; ++dy)
                ans += dfs(grid, i + dx, j + dy, vis);

        return ans;
    }
    // Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>> & grid)
    {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 0 || vis[i][j])
                    continue;
                ans = max(ans, dfs(grid, i, j, vis));
            }
        }
        return ans;
    }
};