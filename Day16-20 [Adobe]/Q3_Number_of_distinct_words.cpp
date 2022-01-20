/*
    Given two integers N and K, the task is to find the number of distinct strings consisting of lowercase alphabets of length N that can be formed with at-most K contiguous vowels. As the answer may be too large, print answer%1000000007.

    Input: N = 1, K = 0
    Output: 21
    Explanation: All the 21 consonants are there which has 0 contiguous vowels and are of length 1.
*/
typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution
{
public:
    ll power(ll a, ll x)
    {
        ll res = 1;
        a %= MOD;
        if (a == 0)
            return 0;

        while (x)
        {
            if (x & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            x >>= 1;
        }
        return res;
    }
    int kvowelwords(int n, int k)
    {

        ll dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        ll sum = 1;

        for (int i = 1; i <= n; ++i)
        {
            dp[i][0] = sum * 21;
            dp[i][0] %= MOD;
            sum = dp[i][0];
            for (int j = 1; j <= k; ++j)
            {
                if (j == i)
                    dp[i][j] = power(5, j);
                else if (j < i)
                    dp[i][j] = dp[i - 1][j - 1] * 5;

                dp[i][j] %= MOD;
                sum += dp[i][j];
                sum %= MOD;
            }
        }
        // for(int i=0; i<=n; ++i)
        // {
        //     for(int j = 0; j<=k; ++j)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return sum;
    }
};