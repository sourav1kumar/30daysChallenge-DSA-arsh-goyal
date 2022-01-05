/*
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.
*/

class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int x, y;
        for (int i = 0; i < n; ++i)
        {
            if (arr[abs(arr[i]) - 1] < 0)
                y = abs(arr[i]);
            else
                arr[abs(arr[i]) - 1] *= (-1);
        }
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] > 0)
                x = i + 1;
        }
        int ans[] = {y, x};
        int *res = ans;
        return res;
    }
};
