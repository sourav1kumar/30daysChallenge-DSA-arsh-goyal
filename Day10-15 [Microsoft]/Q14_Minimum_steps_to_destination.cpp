/*
Given an infinite number line.You start at 0 and can go either to the left or to the right.The condition is that in the ith move, youmust take i steps.Given a destination D, find the minimum number of steps required to reach that destination.
*/
class Solution
{
public:
    int minSteps(int D)
    {
        for (int i = 0; i <= D; ++i)
        {
            int sum = (i * (i + 1)) / 2;
            if (sum >= D && (sum % 2) == (D % 2))
                return i;
        }
    }
};