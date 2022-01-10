/*
Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
*/
string encode(string src)
{
    string ans = "";
    int n = src.size();
    for (int i = 0; i < n; ++i)
    {
        int j = 0;
        while (src[i + j] == src[i])
            j++;
        ans += src[i];
        ans += to_string(j);
        i += j - 1;
    }
    return ans;
}
