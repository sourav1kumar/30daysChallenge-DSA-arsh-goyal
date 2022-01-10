/*
Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Example 1:

Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6

Output:
3 3 4 5 5 5 6
*/
class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for (int i = 0; i < n; ++i)
        {
            pq.push({arr[i], i});
            while (!pq.empty() && pq.top().second <= i - k)
                pq.pop();
            if (i - k >= -1)
                ans.push_back(pq.top().first);
        }
        return ans;
    }
};