/*
    Given an array A of N integers, find any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k.

    Example 1:

    Input:
    N = 5
    A[] = {1,2,1,1,3}
*/
class Solution
{
public:
    vector<int> find3Numbers(vector<int> arr, int n)
    {
        int pre[n], suff[n];
        pre[0] = arr[0], suff[n - 1] = arr[n - 1];

        for (int i = 1; i < n; ++i)
        {
            pre[i] = min(pre[i - 1], arr[i]);
        }
        for (int i = n - 2; i >= 0; --i)
        {
            suff[i] = max(suff[i + 1], arr[i]);
        }
        for (int i = 1; i < n - 1; ++i)
        {
            if (pre[i - 1] < arr[i] && arr[i] < suff[i + 1])
            {
                return {pre[i - 1], arr[i], suff[i + 1]};
            }
        }
        return {};
    }
};