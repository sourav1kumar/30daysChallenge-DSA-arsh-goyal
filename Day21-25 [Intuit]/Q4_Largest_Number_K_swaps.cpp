/*
    Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.


    Example 1:

    Input:
    K = 4
    str = "1234567"
*/
void dfs(string s, string &maxi, int k, int pos)
{
    if (k == 0)
        return;
    char charAtpos = s[pos];
    for (int i = pos + 1; i < s.size(); i++)
    {
        if (charAtpos < s[i])
            charAtpos = s[i];
    }
    if (charAtpos != s[pos])
        k--;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (charAtpos == s[i])
        {
            swap(s[i], s[pos]);
            if (s > maxi)
                maxi = s;

            dfs(s, maxi, k, pos + 1); // this basic backtraking approach
            swap(s[i], s[pos]);
        }
    }
}
string findMaximumNum(string str, int k)
{
    // code here.
    string maxi = str;
    dfs(str, maxi, k, 0);
    return maxi;
}