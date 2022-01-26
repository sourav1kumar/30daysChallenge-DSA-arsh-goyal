/*
    Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

    Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

    Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

    Return the minimum integer k such that she can eat all the bananas within h hours.



    Example 1:

    Input: piles = [3,6,7,11], h = 8
    Output: 4
*/
class Solution
{
public:
    int check(vector<int> piles, int mid)
    {
        int cnt = 0;
        for (auto x : piles)
        {
            cnt += x / mid;
            if (x % mid)
                cnt++;
        }
        return cnt;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int lo = 1, hi = piles[n - 1], ans = 0;
        while (lo <= hi)
        {
            int mid = (hi + lo) / 2;

            if (check(piles, mid) <= h)
            {
                ans = mid, hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};