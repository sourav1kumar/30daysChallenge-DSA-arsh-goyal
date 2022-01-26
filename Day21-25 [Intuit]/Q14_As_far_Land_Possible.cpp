/*
    Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

    Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
    Output: 2
*/
class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size(), one = 0, zero = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                    one++;
                else
                    zero++;

        if (!one || !zero)
            return -1;
        int vis[n][n];
        memset(vis, 0, sizeof(vis));
        queue<vector<int>> que;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                if (grid[i][j])
                    vis[i][j] = 1, que.push({i, j, 0});
        }
        int k[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        int ans = 0;
        while (!que.empty())
        {
            int x = que.front()[0], y = que.front()[1], d = que.front()[2];

            ans = max(ans, d);
            for (int i = 0; i < 4; ++i)
            {
                int xd = x + k[i][0];
                int yd = y + k[i][1];
                if (xd < 0 || yd < 0 || xd == n || yd == n || vis[xd][yd])
                    continue;
                que.push({xd, yd, d + 1});
                vis[xd][yd] = 1;
            }
            que.pop();
        }
        return ans;
    }
};