/*
    Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found,   return the first such range found.
*/
class Solution
{
public:
    pair<int, int> findSmallestRange(int nums[][N], int n, int k)
    {
        vector<pair<int, int>> vec;

        for (int i = 0; i < k; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                vec.push_back({nums[i][j], i});
            }
        }
        sort(vec.begin(), vec.end());

        int mp[k], mini = 1e9, total = 0, j = 0;
        pair<int, int> ans;
        memset(mp, 0, sizeof(mp));

        for (int i = 0; i < n * k; ++i)
        {
            mp[vec[i].second]++;

            if (mp[vec[i].second] == 1)
                total++;

            while (total == k)
            {
                if (j < i && mp[vec[j].second] > 1)
                    mp[vec[j].second]--, j++;
                else
                    break;
            }
            if (total == k)
            {
                if (vec[i].first - vec[j].first + 1 < mini)
                {
                    mini = vec[i].first - vec[j].first + 1;
                    ans = {vec[j].first, vec[i].first};
                }
            }
            // cout<<i<<" "<<j<<" "<<total<<endl;
        }
        return ans;
    }
};