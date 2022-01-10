/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc. In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA” and so on.

*/

class Solution
{
public:
    string colName(long long int n)
    {
        string ans = "";
        long m = 1, num = n;
        ;
        while (num / m > 26)
            m *= 26, num--;
        while (m > 0)
        {
            int t = n / m;
            n -= t * m;
            m /= 26;
            ans += (char)(t + 64);
        }

        int anssz = ans.size();
        for (int i = anssz - 1; i > 0; --i)
        {
            if (ans[i] == '@')
                ans[i] = 'Z', ans[i - 1]--;
        }
        return ans;
    }
};