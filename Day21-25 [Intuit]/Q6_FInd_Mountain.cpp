/*
    Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

    You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

    MountainArray.get(k) returns the element of the array at index k (0-indexed).
    MountainArray.length() returns the length of the array.

    Input: array = [0,1,2,4,2,1], target = 3
    Output: -1
*/

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();
        int lo = 0, hi = n - 1, peak = -1;
        while (lo <= hi)
        {
            int mid = (hi + lo) / 2;
            int val = mountainArr.get(mid), val2 = mountainArr.get(mid + 1);
            if (val > val2)
            {
                peak = mid;
                hi = mid - 1;
            }
            else if (val < val2)
                lo = mid + 1;
            else
            {
                return -1;
            }
        }
        if (peak == -1)
        {
            return -1;
        }

        int flag = 1, ans = -1;

        // left segment
        lo = 0, hi = peak;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            int val = mountainArr.get(mid);
            if (val == target)
            {
                flag = 0;
                ans = mid;
            }
            if (val >= target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        // if no target found
        if (flag)
        {
            // left segment
            lo = peak, hi = n - 1;
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;
                int val = mountainArr.get(mid);
                if (val == target)
                {
                    flag = 0;
                    hi = mid - 1;
                    ans = mid;
                }
                else
                    lo = mid + 1;
            }
        }
        return ans;
    }
};