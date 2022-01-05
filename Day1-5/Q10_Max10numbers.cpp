/*
    Find max 10 numbers in a list having 10M entries.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> max_10_elements(vector<int> a)
{
    int n = a.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; ++i)
    {
        pq.push(a[i]);
        while(pq.size() > 10)
            pq.pop();
    }
    vector<int> ans;
    while(!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
int main()
{
    vector<int> vec = max_10_elements({10,11,12,1763,1,3,-1,98,56,43,986, 100, 32,65});
    
    for(auto x: vec)
        cout<<x<<" ";
    return 0;
}