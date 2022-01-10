/*
M items are to be delivered in a circle of size N. Find the position where the M-th item will be delivered if we start from a given position K. Note that items are distributed at adjacent positions starting from K.
*/

class Solution
{
public:
    int findPosition(int n, int m, int k)
    {
        int pos = 0;
        m--;
        m = m % n;
        pos = k + max(m, 0);
        if (pos > n)
            pos -= n;
        return pos;
    }
};