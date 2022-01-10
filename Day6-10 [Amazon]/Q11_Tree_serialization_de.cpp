/*
Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to the tree and returns it.
*/

class Solution
{
public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        if (!root)
            return {};

        queue<Node *> que;
        vector<int> vec;

        que.push(root);
        vec.push_back(root->data);

        while (!que.empty())
        {
            Node *t = que.front();
            if (t->left)
            {
                que.push(t->left);
                vec.push_back(t->left->data);
            }
            else
                vec.push_back(-1);
            if (t->right)
            {
                que.push(t->right);
                vec.push_back(t->right->data);
            }
            else
                vec.push_back(-1);

            que.pop();
        }
        return vec;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &vec)
    {
        queue<pair<Node *, int>> que;
        Node *dumm = new Node(0);
        que.push({dumm, 1});

        for (auto x : vec)
        {
            Node *temp = que.front().first;
            int t = que.front().second;
            que.pop();
            if (x == -1)
                continue;

            Node *nNode = new Node(x);
            if (t == 1)
            {
                temp->left = nNode;
                que.push({temp->left, 1});
                que.push({temp->left, 2});
            }
            else
            {
                temp->right = nNode;
                que.push({temp->right, 1});
                que.push({temp->right, 2});
            }
        }
        return dumm->left;
    }
};