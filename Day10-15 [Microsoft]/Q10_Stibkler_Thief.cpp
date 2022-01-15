/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i]amount of money present in it.

Example 1:

Input:
n = 6
a[] = {5,5,10,100,10,5}
Output: 110
*/
int FindMaxSum(int arr[], int n)
{
    int ans[n];
    ans[0] = arr[0];
    if (n > 1)
        ans[1] = arr[1];
    if (n > 2)
        ans[2] = arr[2] + arr[0];

    for (int i = 2; i < n; ++i)
    {
        ans[i] = arr[i] + max(ans[i - 2], ans[i - 3]);
    }
    int maxi = 0;
    for (int i = 0; i < n; ++i)
        maxi = max(maxi, ans[i]);
    return maxi;
}