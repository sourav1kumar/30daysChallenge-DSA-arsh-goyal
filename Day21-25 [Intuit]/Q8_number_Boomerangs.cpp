/*
You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Return the number of boomerangs.



Example 1:

Input: points = [[0,0],[1,0],[2,0]]
Output: 2
*/
class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int n = points.size();
        vector<map<int, int>> vec(n);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;
                int dist = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[j][1] - points[i][1]) * (points[j][1] - points[i][1]);
                vec[i][dist]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (auto x : vec[i])
            {
                ans += (x.second) * (x.second - 1);
            }
        }
        return ans;
    }
};