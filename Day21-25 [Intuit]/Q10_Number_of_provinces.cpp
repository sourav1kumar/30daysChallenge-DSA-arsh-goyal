/*
    There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

    A province is a group of directly or indirectly connected cities and no other cities outside of the group.

    You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

    Return the total number of provinces.
*/
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &a)
    {
        int n = a.size(), cc = 0;
        int vis[n + 1];
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < n; ++i)
        {
            if (vis[i] == 0)
            {
                queue<int> que;
                que.push(i);

                while (!que.empty())
                {
                    int j = que.front();
                    vis[j] = 1;

                    for (int k = 0; k < n; ++k)
                    {
                        if (a[j][k] && !vis[k])
                            que.push(k);
                    }
                    que.pop();
                }
                cc++;
            }
        }
        return cc;
    }
};