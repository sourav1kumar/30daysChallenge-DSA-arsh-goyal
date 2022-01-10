/*
In the stock market, a person buys a stock and sells it on some future date. Given the stock prices of N days in an array A[ ] and a positive integer K, find out the maximum profit a person can make in at-most K transactions. A transaction is equivalent to (buying + selling) of a stock and new transaction can start only when the previous transaction has been completed.
*/
class Solution
{
public:
    int maxProfit(int K, int N, int A[])
    {

        // DP of Transaction Count vs Price
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));

        for (int t = 1; t <= K; ++t)
        {
            for (int p = 1; p <= N; ++p)
            {
                dp[t][p] = dp[t][p - 1];
                for (int i = 0; i < p; ++i)
                {
                    dp[t][p] = max(dp[t][p], dp[t - 1][i] + A[p - 1] - A[i]);
                }
            }
        }
        return dp.back().back();
    }
};