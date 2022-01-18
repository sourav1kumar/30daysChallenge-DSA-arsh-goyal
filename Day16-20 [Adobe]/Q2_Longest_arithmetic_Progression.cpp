/*
Given an array called A[] of sorted integers having no duplicates, find the length of the Longest Arithmetic Progression(LLAP)
in it.
*/
class Solution
{
public:
    int lengthOfLongestAP(int a[], int n)
    {
        if (n <= 2)
            return n;
        vector<unordered_map<int, int>> dp(n);
        int maxlen = 2;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int diff = a[j] - a[i];
                if (dp[i].find(diff) != dp[i].end())
                {
                    dp[j][diff] = dp[i][diff] + 1;
                }
                else
                    dp[j][diff] = 2;
                maxlen = max(maxlen, dp[j][diff]);
            }
        }
        return maxlen;
    }
};