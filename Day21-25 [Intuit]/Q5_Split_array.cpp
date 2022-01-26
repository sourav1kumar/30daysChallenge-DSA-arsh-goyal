/*
    Given an array nums which consists of non -
    negative integers and an integer m,
    you can split the array into m non - empty continuous subarrays.

    Write an algorithm to minimize the largest sum among these m subarrays.

    Example 1 :

    Input : nums = [ 7, 2, 5, 10, 8 ], m = 2 
    Output : 18
*/
class Solution
{
public:
    bool check(vector<int> nums, int m, int sum)
    {
        int n = nums.size();
        int total = 0, sub = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > sum)
                return false;
            if (total + nums[i] <= sum)
                total += nums[i];
            else
            {
                sub++;
                total = nums[i];
            }
        }
        sub++;
        return (sub <= m);
    }
    int splitArray(vector<int> &nums, int m)
    {
        int lo = 0, hi = 1e9, ans = 0;
        while (lo <= hi)
        {
            long mid = (hi + lo) / 2;
            if (check(nums, m, mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};