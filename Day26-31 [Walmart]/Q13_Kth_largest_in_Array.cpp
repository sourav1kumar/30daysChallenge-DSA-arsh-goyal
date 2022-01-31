/*
    You are given an array of strings nums and an integer k. Each string in nums represents an integer without leading zeros.

    Return the string that represents the kth largest integer in nums.

    Input: nums = ["3","6","7","10"], k = 4
    Output: "3"
*/
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        vector<string> vec[101];
        for(auto x: nums)
        {
            vec[x.size()].push_back(x);
        }
        for(int i=0; i<101; ++i)
        {
            sort(vec[i].begin(), vec[i].end());
            reverse(vec[i].begin(), vec[i].end());
        }
        for(int i=100; i>0; --i)
        {
            if(vec[i].size() < k)
            {
                k -= vec[i].size();
                continue;
            }
            for(auto x: vec[i])
            {
                if(k == 1)
                    return x;
                k--;
            }
        }
        return "";
    }
};