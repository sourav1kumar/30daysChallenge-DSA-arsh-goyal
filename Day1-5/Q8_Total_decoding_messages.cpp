/*
You have to determine the total number of ways that message can be decoded, as the answer can be large return the answer modulo 1e9 + 7.
*/

int CountWays(string str)
{
    int n = str.size();

    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    if (str[0] > '0')
        dp[1] = 1;
    else
        return 0;

    for (int i = 1; i < n; ++i)
    {
        if (str[i] > '0')
            dp[i + 1] += dp[i];

        if (str[i - 1] > '0' && (str[i - 1] - '0') * 10 + (str[i] - '0') <= 26)
            dp[i + 1] += dp[i - 1];
        dp[i + 1] = dp[i + 1] % 1000000007;
    }
    return dp[n];
}