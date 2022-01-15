/*
Given a binary tree and an integer X. Your task is to complete the function countSubtreesWithSumX() that returns the count of the number of subtress having total node’s data sum equal to the value X.
*/
int ans = 0;
int dfs(Node *root, int X)
{
    if (!root)
        return 0;
    int sum = root->data + dfs(root->left, X) + dfs(root->right, X);

    if (sum == X)
    {
        ans++;
    }
    return sum;
}
int countSubtreesWithSumX(Node *root, int X)
{
    ans = 0;
    int t = dfs(root, X);
    return ans;
}