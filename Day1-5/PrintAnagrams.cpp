/*
Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array.

Example:

Input:
N = 5
words[] = {act,god,cat,dog,tac}

Output:
god dog
act cat tac
*/

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& slist) {
        int n = slist.size();
        
        unordered_map<string, vector<string>> mpp;
        
        for(int i=0; i<n; ++i)
        {
            string t = slist[i];
            sort(t.begin(), t.end());
            mpp[t].push_back(slist[i]);
        }
        vector<vector<string>> ans;
        
        for(auto x: mpp)
            ans.push_back(x.second);
        return ans;
    }
};