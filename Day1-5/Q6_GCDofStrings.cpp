/*
For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
*/

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        int n = str1.size(), m = str2.size();
        int tsz = __gcd(n, m);
        string t = str1.substr(0, tsz), sd1 = "", sd2 = "";

        for (int i = 0; i < n; i += tsz)
            sd1 += t;
        for (int i = 0; i < m; i += tsz)
            sd2 += t;
        if (sd1 == str1 && sd2 == str2)
            return t;
        return "";
    }
};