/*
Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number k.
*/

class Solution
{
public:
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {
        int i = 0, j = 0;
        long long prod = 1;
        long long comb = 0;

        while (j < n)
        {
            prod *= a[j];

            while (i < j && prod >= k)
            {
                prod /= a[i];
                i++;
            }

            if (prod < k)
                comb += j - i + 1;
            j++;
        }
        return comb;
    }
};