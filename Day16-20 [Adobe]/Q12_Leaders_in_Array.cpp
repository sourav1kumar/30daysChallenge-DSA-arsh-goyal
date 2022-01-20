/*
    Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader.



    Example 1:

    Input:
    n = 6
    A[] = {16,17,4,3,5,2}
    Output: 17 5 2
*/
class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(int a[], int n)
    {
        int suff[n + 1];
        suff[n] = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            suff[i] = max(suff[i + 1], a[i]);
            // cout<<suff[i]<<" "<<suff[i+1]<<endl;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == suff[i])
                ans.push_back(a[i]);
        }
        return ans;
    }
};