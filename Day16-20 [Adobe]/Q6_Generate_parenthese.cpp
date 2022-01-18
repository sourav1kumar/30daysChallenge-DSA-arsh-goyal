/*
    Given an integer N representing the number of pairs of parentheses, the task is to generate all combinations of well-formed(balanced) parentheses.


    Example 1:

    Input:
    N = 3
    Output:
    ((()))
    (()())
    (())()
    ()(())
    ()()()
*/
class Solution
{
public:
    vector<string> ans;
    void calc(int open, int close, string tmp)
    {
        if (open < 0 || close < 0 || open > close)
            return;
        if (open == 0 && close == 0)
        {
            ans.push_back(tmp);
            return;
        }
        if (open >= 0)
        {
            calc(open - 1, close, tmp + '(');
        }
        if (close >= 0)
        {
            calc(open, close - 1, tmp + ')');
        }
    }
    vector<string> AllParenthesis(int n)
    {
        calc(n, n, "");
        return ans;
    }
};