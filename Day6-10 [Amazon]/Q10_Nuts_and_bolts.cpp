/*
Given a set of N nuts of different sizes and N bolts of different sizes. There is a one-one mapping between nuts and bolts. Match nuts and bolts efficiently.

Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.
The elements should follow the following order ! # $ % & * @ ^ ~ .

Example 1:

Input: 
N = 5
nuts[] = {@, %, $, #, ^}
bolts[] = {%, @, #, $ ^}
Output: 
# $ % @ ^
# $ % @ ^
*/

class Solution
{
public:
    void matchPairs(char nuts[], char bolts[], int n)
    {
        int j = 0;
        while (j < n)
        {
            int cc = 0;
            for (int i = 0; i < n; ++i)
            {
                if (nuts[i] < bolts[j])
                    cc++;
            }
            // cout<<cc<<" "<<j<<" "<<bolts[j]<<endl;
            if (cc == j)
                j++;
            else
            {
                swap(bolts[j], bolts[cc]);
            }
        }
        for (int i = 0; i < n; ++i)
            nuts[i] = bolts[i];
    }
};