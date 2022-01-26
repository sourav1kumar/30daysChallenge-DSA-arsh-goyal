/*
    Given a n * n matrix grid of 0's and 1's only. We want to represent the grid with a Quad-Tree.

    Return the root of the Quad-Tree representing the grid.

    Input: grid = [[0,1],[1,0]]
    Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]

*/
class Solution
{
public:
    Node *dfs(vector<vector<int>> grid, int left, int right, int top, int down)
    {
        int size = (down - top + 1) * (right - left + 1);
        // cout<<left<<" "<<right<<" "<<top<<" "<<down<<" "<<size<<endl;
        Node *root = new Node;
        int one = 0, zero = 0;

        for (int i = top; i <= down; ++i)
        {
            for (int j = left; j <= right; ++j)
            {
                if (grid[i][j])
                    one++;
                else
                    zero++;
            }
        }
        // cout<<one<<" "<<zero<<endl;
        if (one == size || zero == size)
        {
            root->val = (one == size) ? 1 : 0;
            root->isLeaf = 1;
            return root;
        }
        // cout<<"not leaf"<<endl;
        root->val = 1;
        root->isLeaf = 0;
        int cols = right - left + 1, rows = down - top + 1;

        root->topLeft = dfs(grid, left, left + cols / 2 - 1, top, top + rows / 2 - 1);

        root->topRight = dfs(grid, left + cols / 2, right, top, top + rows / 2 - 1);

        root->bottomLeft = dfs(grid, left, left + cols / 2 - 1, top + rows / 2, down);

        root->bottomRight = dfs(grid, left + cols / 2, right, top + rows / 2, down);

        return root;
    }
    Node *construct(vector<vector<int>> &grid)
    {
        int n = grid.size();
        return dfs(grid, 0, n - 1, 0, n - 1);
    }
};