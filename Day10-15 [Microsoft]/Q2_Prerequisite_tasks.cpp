/*
There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.
*/

bool isPossible(int n, vector<pair<int, int>> &pre)
{
    // Code here
    vector<vector<int>> adj(n, vector<int>());
    vector<int> indegree(n, 0);
    for (auto it : pre)
    {
        adj[it.second].push_back(it.first);
        indegree[it.first]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    if (q.empty())
        return false;

    vector<int> ans;
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        ans.push_back(temp);
        for (auto it : adj[temp])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    if (ans.size() == n)
        return true;
    return false;
}