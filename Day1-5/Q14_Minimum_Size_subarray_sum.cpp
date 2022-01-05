/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
*/

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int mini = INT_MAX, start = 0, end = 0, sum = 0;

        while (end < n)
        {

            if (sum < target)
            {
                sum += nums[end];
                end++;
            }
            if (sum >= target)
            {
                while (start < end && sum >= target)
                {
                    mini = min(mini, end - start);
                    sum -= nums[start];
                    start++;
                }
            }
        }
        if (mini == INT_MAX)
            return 0;
        return mini;
    }
};