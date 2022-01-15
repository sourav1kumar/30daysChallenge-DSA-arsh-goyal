/*
Given a matrix of size r*c. Traverse the matrix in spiral form.

Example 1:

Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/
vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    int top = 0, down = r - 1, left = 0, right = c - 1;
    vector<int> ans;

    while ((top <= down) && (left <= right))
    {
        for (int i = left; i <= right; ++i)
            ans.push_back(matrix[top][i]);
        top++;
        if (top > down)
            break;

        for (int i = top; i <= down; ++i)
            ans.push_back(matrix[i][right]);
        right--;
        if (left > right)
            break;

        for (int i = right; i >= left; --i)
            ans.push_back(matrix[down][i]);
        down--;
        if (top > down)
            break;

        for (int i = down; i >= top; --i)
            ans.push_back(matrix[i][left]);
        left++;
        if (left > right)
            break;
    }
    return ans;
}
}
;