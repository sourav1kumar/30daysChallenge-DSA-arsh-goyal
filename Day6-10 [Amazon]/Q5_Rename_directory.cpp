/*
Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s. The task is to implement a search query for the phone directory. Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order.

Input:
n = 3
contact[] = {"geeikistest", "geeksforgeeks",
"geeksfortest"}
s = "geeips"

Output:
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0

*/

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        int m = s.size();
        vector<vector<string>> vec(m);
        
        for(int i=0; i<n; ++i)
        {
            int t = min((int)contact[i].size(), m);
            for(int j=0; j<t; ++j)
            {
                if(s[j] == contact[i][j])
                    vec[j].push_back(contact[i]);
                else
                    break;
            }
        }
        
        for(int i=0; i<m; ++i)
            if(vec[i].size() == 0)
                vec[i].push_back("0");
            else
                sort(vec[i].begin(), vec[i].end());
        
        return vec;
    }
};