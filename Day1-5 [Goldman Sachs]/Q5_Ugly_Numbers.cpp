/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included. Write a program to find Nth Ugly Number.
*/
class Solution
{
public:
    // #define ull unsigned long long
    /* Function to get the nth ugly number*/
    ull getNthUglyNo(int n)
    {
        int idx2 = 0, idx3 = 0, idx5 = 0, count = 1;
        ull next2 = 2, next3 = 3, next5 = 5;
        ull uglyNo[n + 1];
        uglyNo[0] = 1;
        while (count < n)
        {
            next2 = uglyNo[idx2] * 2;
            next3 = uglyNo[idx3] * 3;
            next5 = uglyNo[idx5] * 5;

            ull next = min(next2, next3);
            next = min(next, next5);

            uglyNo[count++] = next;
            if (next == next2)
                idx2++;
            if (next == next3)
                idx3++;
            if (next == next5)
                idx5++;
        }
        return uglyNo[n - 1];
    }
};