/*
Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.


Example 1:

Input: A = "aabc"

Output: "a#bb"
*/

string FirstNonRepeating(string A)
{
    // Code here
    string ans = "";
    int occur[26];
    memset(occur, 0, sizeof(occur));

    int idx[26];
    memset(idx, -1, sizeof(idx));

    for (int i = 0; i < A.size(); ++i)
    {
        occur[A[i] - 'a']++;
        if (occur[A[i] - 'a'] == 1)
            idx[A[i] - 'a'] = i;

        int att = INT_MAX, ch = 0;
        for (int j = 0; j < 26; ++j)
        {
            if (occur[j] == 1 && idx[j] < att)
            {
                att = idx[j];
                ch = j;
            }
        }
        if (att == INT_MAX)
            ans += "#";
        else
            ans += 'a' + ch;
    }
    return ans;
}