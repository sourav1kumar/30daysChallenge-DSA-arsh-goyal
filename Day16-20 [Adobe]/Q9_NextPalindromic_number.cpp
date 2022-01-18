/*
    Given a palindromic number N in the form of string. The task is to find the smallest palindromic number greater than N using the same set of digits as in N.

    Example 1:

    Input:
    N = "35453"
    Output:
    53435
    Explanation: Next higher palindromic
    number is 53435.
*/
class Solution
{
public:
    string nextPalin(string s)
    {
        int n = s.size(), idx = -1;

        for (int i = n / 2 - 1; i > 0; --i)
        {
            if (s[i] > s[i - 1])
            {
                idx = i - 1;
                break;
            }
        }
        if (idx == -1)
            return "-1";

        int j = n / 2 - 1;

        while (s[j] <= s[idx])
            j--;
        swap(s[idx], s[j]);
        reverse(s.begin() + idx + 1, s.begin() + n / 2);
        for (int i = 0; i < n / 2; ++i)
            s[n - i - 1] = s[i];
        return s;
    }
};