/*
Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.
*/
vector<int> subarraySum(int arr[], int n, long long s)
{
    int left = 0, right = 0;
    long long tmp = 0;
    while (right < n)
    {
        tmp += arr[right++];
        while (tmp > s)
        {
            tmp -= arr[left++];
        }
        if (tmp == s)
            return {left + 1, right};
    }
    return {-1};
}