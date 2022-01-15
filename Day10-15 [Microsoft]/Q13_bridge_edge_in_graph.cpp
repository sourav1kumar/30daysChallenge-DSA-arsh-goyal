/*
Given a Graph of V vertices and E edges and another edge(c - d), the task is to find if the given edge is a Bridge. i.e., removing the edge disconnects the graph.
*/

void dfs(vector<int> adj[], int i, bool vis[])
{
    // cout<<i<<" ";
    if (vis[i])
        return;
    vis[i] = 1;
    for (auto x : adj[i])
        dfs(adj, x, vis);
}
int isBridge(int n, vector<int> adj[], int c, int d)
{
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));

    vis[c] = 1;
    for (auto x : adj[c])
    {
        if (x == d)
            continue;
        dfs(adj, x, vis);
    }
    if (vis[d])
        return 0;
    return 1;
}