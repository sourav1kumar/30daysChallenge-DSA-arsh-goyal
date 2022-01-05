/*
Given a pattern containing only I's and D's. I for increasing and D for decreasing.
Devise an algorithm to print the minimum number following that pattern.
Digits from 1-9 and digits can't repeat.
*/

string printMinNumberForPattern(string s)
{
    stack<int> st;
    string ans = "";
    int cnt = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'D')
            st.push(cnt++);
        else
        {
            st.push(cnt++);
            while (!st.empty())
            {
                ans += to_string(st.top());
                st.pop();
            }
        }
    }
    st.push(cnt++);
    while (!st.empty())
    {
        ans += to_string(st.top());
        st.pop();
    }
    return ans;
}