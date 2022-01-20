/*
    Given an array of names (consisting of lowercase characters) of candidates in an election. A candidate name in array represents a vote casted to the candidate. Print the name of candidate that received Max votes. If there is tie, print lexicographically smaller name.

    Example 1:

    Input:
    n = 13
    Votes[] = {john,johnny,jackie,johnny,john 
    jackie,jamie,jamie,john,johnny,jamie,
    johnny,john}
    Output: john 4
*/

vector<string> winner(string s[], int n)
{
    map<string, int> mpp;
    for (int i = 0; i < n; ++i)
    {
        mpp[s[i]]++;
    }

    int maxi = 0;
    for (auto x : mpp)
        maxi = max(maxi, x.second);

    string ans;
    for (auto x : mpp)
    {
        if (x.second == maxi)
        {
            ans = x.first;
            break;
        }
    }
    string num = to_string(maxi);

    return {ans, num};
}
}
;