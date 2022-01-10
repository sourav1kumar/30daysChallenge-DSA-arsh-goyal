/*
Due to the rise of covid-19 cases in India, this year BCCI decided to organize knock-out matches in IPL rather than a league.

Today is matchday 2 and it is between the most loved team Chennai Super Kings and the most underrated team - Punjab Kings. Stephen Fleming, the head coach of CSK, analyzing the batting stats of Punjab. He has stats of runs scored by all N players in the previous season and he wants to find the maximum score for each and every contiguous sub-list of size K to strategize for the game.

Example 1:

Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6

Output:
3 3 4 5 5 5 6
*/

vector<int> max_of_subarrays(vector<int> arr, int n, int k)
{
    priority_queue<pair<int, int>> pq;
    vector<int> ans;

    for (int i = 0; i < k; ++i)
        pq.push({arr[i], i});
    ans.push_back(pq.top().first);

    for (int i = k; i < n; ++i)
    {
        while (!pq.empty() && pq.top().second <= i - k)
            pq.pop();
        pq.push({arr[i], i});
        ans.push_back(pq.top().first);
    }
    return ans;
}