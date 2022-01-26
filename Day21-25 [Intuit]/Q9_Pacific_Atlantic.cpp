int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
void BFS(vector<vector<int>> &grid, queue<pair<int, int>> q, int n, int m, vector<vector<bool>> &vis)
{
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newX = x + dir[i][0];
                int newY = y + dir[i][1];
                if (newX < 0 or newY < 0 or newX >= n or newY >= m or vis[newX][newY] or grid[x][y] > grid[newX][newY])
                    continue;
                vis[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    vector<vector<bool>> vis1(n, vector<bool>(m, false));
    vector<vector<bool>> vis2(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 or j == 0)
            {
                q1.push({i, j});
                vis1[i][j] = true;
            }
            if (i == n - 1 or j == m - 1)
            {
                q2.push({i, j});
                vis2[i][j] = true;
            }
        }
    }
    BFS(heights, q1, n, m, vis1);
    BFS(heights, q2, n, m, vis2);
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis1[i][j] and vis2[i][j])
            {
                ans.push_back({i, j});
            }
        }
    }

    return ans;
}