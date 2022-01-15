/*
Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

Example 1:

Input:
N = 5, K = 3
A[] = {0,0,2,1,1}
Output: 0 0 1 2 $
*/
class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        set<vector<int>> ans_set;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int lo = j + 1, hi = n - 1;
                while (lo < hi)
                {
                    int t = arr[i] + arr[j] + arr[lo] + arr[hi];
                    if (t == k)
                    {
                        int lo_dash = lo + 1, hi_dash = hi - 1;
                        while (lo_dash < hi && arr[lo] == arr[lo_dash])
                            lo_dash++;
                        while (hi_dash > lo && arr[hi] == arr[hi_dash])
                            hi_dash--;
                        ans_set.insert({arr[i], arr[j], arr[lo], arr[hi]});
                        lo = lo_dash - 1;
                        hi = hi_dash + 1;
                    }
                    if (t > k)
                        hi--;
                    else
                        lo++;
                }
            }
        }
        vector<vector<int>> ans;
        for (auto x : ans_set)
            ans.push_back(x);
        return ans;
    }
};