/*
Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
*/

bool canPair(vector<int> a, int k)
{

    unordered_map<int, int> mp;
    int n = a.size();
    for (int i = 0; i < a.size(); i++)
        mp[a[i] % k]++;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % k == 0)
        {
            if (mp[0] & 1)
                return 0;
        }
        else if (mp[a[i] % k] != mp[k - a[i] % k])
            return 0;
    }
    return 1;
}