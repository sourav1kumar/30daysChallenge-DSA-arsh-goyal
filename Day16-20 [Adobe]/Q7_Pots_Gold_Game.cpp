/*
    Two players X and Y are playing a game in which there are pots of gold arranged in a line, each containing some gold coins. They get alternating turns in which the player can pick a pot from one of the ends of the line. The winner is the player who has a higher number of coins at the end. The objective is to maximize the number of coins collected by X, assuming Y also plays optimally.

    Return the maximum coins X could get while playing the game. Initially, X starts the game.


    Example 1:

    Input:
    N = 4
    Q[] = {8, 15, 3, 7}
    Output: 22
*/
class Solution
{
public:
    map<pair<int, int>, int> mpp;

    int coins(vector<int> vec, int start, int end)
    {
        if (start > end)
            return 0;

        if (mpp[{start, end}])
            return mpp[{start, end}];
        int t1 = vec[start] + coins(vec, start + 1, end - 1);
        int t2 = vec[start] + coins(vec, start + 2, end);
        int t3 = vec[end] + coins(vec, start + 1, end - 1);
        int t4 = vec[end] + coins(vec, start, end - 2);
        int maxi = min(t1, t2);
        maxi = max(maxi, min(t3, t4));

        return mpp[{start, end}] = maxi;
    }
    int maxCoins(vector<int> &A, int n)
    {
        int ans = coins(A, 0, n - 1);

        return ans;
    }
};