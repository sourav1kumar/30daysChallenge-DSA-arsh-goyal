/*
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.
*/

class Solution
{
public:
    int longestMountain(vector<int> &a)
    {
        int n = a.size();
        int pre[n], suff[n];
        pre[0] = 1, suff[n - 1] = 1;

        for (int i = 1; i < n; ++i)
        {
            if (a[i] > a[i - 1])
                pre[i] = pre[i - 1] + 1;
            else
                pre[i] = 1;
            if (a[n - i] < a[n - i - 1])
                suff[n - i - 1] = suff[n - i] + 1;
            else
                suff[n - i - 1] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (pre[i] > 1 && suff[i] > 1)
                ans = max(ans, pre[i] + suff[i] - 1);
        }
        if (ans < 3)
            return 0;
        return ans;
    }
};