/*
Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.
*/

string change(int n)
{
    string t = "";
    int j = 0;
    while ((1 << j) <= n)
    {
        if ((1 << j) & n)
            t += '1';
        else
            t += '0';
        j++;
    }
    reverse(t.begin(), t.end());
    return t;
}
vector<string> generate(int N)
{
    vector<string> ans;
    for (int i = 1; i <= N; ++i)
    {
        ans.push_back(change(i));
    }
    return ans;
}