/*
    Given N dots that form a triangle such that ith line contains i number of dots.

        .
       . .
      . . .
     . . . .
    Find the minimum hieght H of the triangle that can be formed using these N dots.
*/
class Solution
{
public:
    int height(int N)
    {
        int tmp = 1, ans = 1;
        while ((tmp * (tmp + 1)) / 2 <= N)
        {
            ans = tmp;
            tmp++;
        }
        return ans;
    }
};
