/*
    Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

    A grid is said to be valid if all the cells above the main diagonal are zeros.

    Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.
*/
class Solution
{
public:
    int minSwaps(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int zeroes[n];
        memset(zeroes, 0, sizeof(zeroes));

        for (int i = 0; i < n; ++i)
        {
            int cc = 0;
            for (int j = n - 1; j >= 0; --j)
            {
                if (grid[i][j] == 1)
                {
                    zeroes[i] = cc;
                    cc = 0;
                    break;
                }
                cc++;
                // cout<<cc<<" ";
            }
            zeroes[i] = max(zeroes[i], cc);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int idx = -1;
            for (int j = i; j < n; ++j)
            {
                if (zeroes[j] >= n - 1 - i)
                {
                    idx = j;
                    break;
                }
            }
            if (idx == -1)
                return -1;

            ans += idx - i;
            int tmp = zeroes[idx];

            for (int j = idx; j > i; --j)
                zeroes[j] = zeroes[j - 1];
            zeroes[i] = tmp;
        }
        return ans;
    }
};