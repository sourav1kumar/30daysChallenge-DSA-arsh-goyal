/*
    There are n pieces arranged in a line, and each piece is colored either by 'A' or by 'B'. You are given a string colors of length n where colors[i] is the color of the ith piece.

    Alice and Bob are playing a game where they take alternating turns removing pieces from the line. In this game, Alice moves first.

    Assuming Alice and Bob play optimally, return true if Alice wins, or return false if Bob wins.

    Example 1:

    Input: colors = "AAABABB"
    Output: true
*/
class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int a_count = 0, b_count = 0, as = 0, bs = 0;
        for (auto x : colors)
        {
            if (x == 'A')
            {
                as++;
                b_count += max(bs - 2, 0);
                bs = 0;
            }
            else
            {
                bs++;
                a_count += max(as - 2, 0);
                as = 0;
            }
        }
        a_count += max(as - 2, 0);
        b_count += max(bs - 2, 0);
        return (a_count > b_count);
    }
};