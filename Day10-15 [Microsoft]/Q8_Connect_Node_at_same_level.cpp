/*
Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.

Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.
*/
class Solution
{
public:
    // Function to connect nodes at same level.
    void connect(Node *root)
    {
        if (!root)
            return;

        queue<pair<Node *, int>> que;
        que.push({root, 0});
        while (!que.empty())
        {
            Node *prev = que.front().first;
            int d = que.front().second;
            que.pop();
            while (!que.empty() && que.front().second == d)
            {
                prev->nextRight = que.front().first;
                if (prev->left)
                    que.push({prev->left, d + 1});
                if (prev->right)
                    que.push({prev->right, d + 1});
                prev = que.front().first;
                que.pop();
            }
            if (prev->left)
                que.push({prev->left, d + 1});
            if (prev->right)
                que.push({prev->right, d + 1});
        }
    }
};