/*
    Given a number and its reverse. Find that number raised to the power of its own reverse.
    Note: As answers can be very large, print the result modulo 109 + 7.

    Example 1:

    Input:
    N = 2
    Output: 4
*/
long long power(int n, int r)
{
    long long res = 1, tmp = n;
    if (n == 0)
        return 0;
    while (r)
    {
        if (r & 1)
        {
            res *= tmp;
            res = res % mod;
        }
        tmp = tmp * tmp;
        tmp = tmp % mod;
        r >>= 1;
    }
    return res;
}