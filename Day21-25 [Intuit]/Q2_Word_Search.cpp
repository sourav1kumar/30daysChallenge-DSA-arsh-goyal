/*
Given a 2D board of letters and a word.Check if the word exists in the board.The word can be constructed from letters of adjacent cells only.ie - horizontal or vertical neighbors.The same letter cell can not be used more than once.

                                                                                                                                                                Example 1 :

    Input : board = {{a, g, b, c}, {q, e, e, l}, {g, b, k, s}},
            word = "geeks" Output : 1 
*/
vector<vector<char>> a;
int n, m, vis[101][101], len, flag = 0;
string w;
void dfs(int i, int r, int c)
{
    if (r < 0 || c < 0 || r == n || c == m || vis[r][c] || flag)
        return;
    if (i == len)
    {
        flag = 1;
        return;
    }
    if (w[i] != a[r][c])
        return;
    vis[r][c] = 1;
    dfs(i + 1, r - 1, c);
    dfs(i + 1, r + 1, c);
    dfs(i + 1, r, c + 1);
    dfs(i + 1, r, c - 1);
    vis[r][c] = 0;
}
bool isWordExist(vector<vector<char>> &board, string word)
{
    memset(vis, 0, sizeof(vis));
    n = board.size(), m = board[0].size(), len = word.size();
    a = board;
    w = word;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (board[i][j] == word[0])
                dfs(0, i, j);
    return flag;
}