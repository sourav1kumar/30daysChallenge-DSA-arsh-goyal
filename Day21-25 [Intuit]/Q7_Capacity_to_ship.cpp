/*
    A conveyor belt has packages that must be shipped from one port to another within days days.

    The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

    Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.



    Example 1:

    Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
    Output: 15
*/
class Solution
{
public:
    bool check(int mid, vector<int> weights, int days)
    {
        int sub = 0, total = 0;
        for (auto x : weights)
        {
            if (x > mid)
                return false;
            if (total + x <= mid)
                total += x;
            else
            {
                sub++;
                total = x;
            }
        }
        sub++;
        return (sub <= days);
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int sum = 0, ans = 0;
        for (auto x : weights)
        {
            sum += x;
        }
        int lo = 1, hi = sum;
        while (lo <= hi)
        {
            long mid = (hi + lo) / 2;
            if (check(mid, weights, days))
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