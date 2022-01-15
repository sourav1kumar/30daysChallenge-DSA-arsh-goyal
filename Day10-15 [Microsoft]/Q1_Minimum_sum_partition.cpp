/*
Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference
Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
*/

int minDifference(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
    }
    int tmp = sum;
    sum /= 2;
    bool dp[n + 1][sum + 2];
    memset(dp, false, sizeof(dp));

    sort(arr, arr + n);
    for (int i = 0; i < n + 1; ++i)
        dp[i][0] = 1;

    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < sum + 1; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    int maxi = 0;
    for (int i = 0; i <= sum + 1; i++)
    {
        if (dp[n][i])
            maxi = i;
    }
    return (tmp - 2 * maxi);
}