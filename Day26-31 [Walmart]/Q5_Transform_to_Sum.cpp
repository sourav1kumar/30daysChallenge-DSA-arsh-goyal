/*
    Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.
*/
class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int dfs(Node *root)
    {
        if (!root)
            return 0;
        int tmp = dfs(root->left) + dfs(root->right);
        int till = tmp + root->data;
        root->data = tmp;
        return till;
    }
    void toSumTree(Node *node)
    {
        dfs(node);
    }
};