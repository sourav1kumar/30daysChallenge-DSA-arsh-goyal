/*
    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.


    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: [0,1]
*/
class Solution
{
public:
    vector<int> findOrder(int num, vector<vector<int>> &pre)
    {

        vector<vector<int>> adj(num, vector<int>());
        vector<int> indegree(num, 0);
        for (int i = 0; i < pre.size(); i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }

        queue<int> q;
        for (int i = 0; i < num; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        if (q.empty())
            return ans;
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            ans.emplace_back(top);
            for (auto it : adj[top])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        if (ans.size() == num)
            return ans;
        else
            return {};
    }
};