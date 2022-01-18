/*
    Given two numbers n and x, find out the total number of ways n can be expressed as sum of xth power of unique natural numbers.

    Input: n = 100, x = 2
    Output: 3
    Explanation: 100 = 102
    62 + 82 and 12 + 32 + 42 + 52 + 72
    Hence total 3 possibilities.
*/
class Solution
{
public:
    long long numOfWays(int n, int x)
    {
        int j = 1, pj = 1;
        vector<int> vec;
        while (pj <= n)
        {
            vec.push_back(pj);
            j++;
            pj = pow(j, x);
        }
        int size = vec.size();

        long long dp[size + 1][n + 1];

        for (int i = 0; i <= n; ++i)
            dp[0][i] = 0;
        for (int i = 0; i <= size; ++i)
            dp[i][0] = 1;
        for (int i = 1; i <= size; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (vec[i - 1] <= j)
                    dp[i][j] += dp[i - 1][j - vec[i - 1]];
            }
        }
        return dp[size][n];
    }
};
