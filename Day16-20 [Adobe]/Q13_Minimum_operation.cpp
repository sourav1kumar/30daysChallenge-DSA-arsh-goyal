/*
    Given two Arrays A[] and B[] of length N and M respectively. Find the minimum number of insertions and deletions on the array A[], required to make both the arrays identical.
    Note: Array B[] is sorted and all its elements are distinct, operations can be performed at any index not necessarily at end.



    Example 1:

    Input:
    N = 5, M = 3
    A[] = {1, 2, 5, 3, 1}
    B[] = {1, 3, 5}
*/
class Solution
{
public:
    int LIS(vector<int> v)
    {
        if (v.size() == 0) // boundary case
            return 0;

        vector<int> tail(v.size(), 0);
        int length = 1; // always points empty slot in tail

        tail[0] = v[0];

        for (int i = 1; i < v.size(); i++)
        {

            auto b = tail.begin(), e = tail.begin() + length;
            auto it = lower_bound(b, e, v[i]);

            if (it == tail.begin() + length)
                tail[length++] = v[i];
            else
                *it = v[i];
        }

        return length;
    }
    int minInsAndDel(int A[], int B[], int n, int m)
    {

        vector<int> vec, tmp;
        for (int i = 0; i < m; ++i)
            tmp.push_back(B[i]);
        for (int i = 0; i < n; ++i)
        {
            if (binary_search(tmp.begin(), tmp.end(), A[i]))
                vec.push_back(A[i]);
        }
        int ans = n - vec.size();
        int t = LIS(vec);
        ans += vec.size() - t + m - t;
        return ans;
    }
};