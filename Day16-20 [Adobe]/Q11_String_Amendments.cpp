/*
    Given a string which is basically a sentence without spaces between words. However the first letter of every word is in uppercase. You need to print this sentence after following amendments:
    (i) Put a single space between these words
    (ii) Convert the uppercase letters to lowercase.
    Note: The first character of the string can be both uppercase/lowercase.

    Example 1:

    Input:
    s = "BruceWayneIsBatman"
    Output: bruce wayne is batman
    Explanation: The words in the string are
    "Bruce", "Wayne", "Is", "Batman".
*/
class Solution
{
public:
    string amendSentence(string s)
    {
        int n = s.size();
        string ans = "";
        if (s[0] < 'a')
            ans += ((s[0] - 'A') + 'a');
        else
            ans += s[0];

        for (int i = 1; i < n; ++i)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                ans += ' ';
                ans += ((s[i] - 'A') + 'a');
            }
            else
                ans += s[i];
        }
        return ans;
    }
};