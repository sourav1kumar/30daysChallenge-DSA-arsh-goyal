/*
Given a keypad as shown in the diagram, and an N digit number which is represented by array a[ ], the task is to list all words which are possible by pressing these numbers.
*/
class Solution
{
public:
    string cha[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> ans;
    void poss(int a[], int i, int n, string str)
    {
        if (i == n)
        {
            ans.push_back(str);
            return;
        }
        for (auto x : cha[a[i] - 2])
        {
            poss(a, i + 1, n, str + x);
        }
    }
    // Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int n)
    {
        poss(a, 0, n, "");
        return ans;
    }
};