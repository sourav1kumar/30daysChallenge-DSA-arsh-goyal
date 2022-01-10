/*
An encoded string (s) is given, the task is to decode it. The pattern in which the strings were encoded were as follows
original string: abbbababbbababbbab 
encoded string : 3[a3[b]1[ab]]
*/

class Solution
{
public:
    string decodeString(string s)
    {
        stack<pair<string, int>> st;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            string tmp = "";
            while (s[i] >= '0' && s[i] <= '9')
            {
                tmp += s[i++];
            }
            if (tmp > "")
                i++, st.push({"[", stoi(tmp)});
            cout << tmp << endl;

            tmp = "";
            while (s[i] >= 'a' && s[i] <= 'z')
            {
                tmp += s[i++];
            }
            cout << tmp << endl;
            st.push({tmp, 0});
            if (s[i] == ']')
            {
                string add = "", res = "";
                while (!st.empty() && st.top().second == 0)
                {
                    add = st.top().first + add;
                    st.pop();
                }
                int repeat = st.top().second;
                while (repeat--)
                {
                    res += add;
                }
                cout << add << " " << repeat << " " << res << endl;
                if (!st.empty())
                    cout << st.top().first << " " << st.top().second << endl;
                st.pop();
                st.push({res, 0});
            }
            else
                i--;
        }
        string ans = "";
        while (!st.empty())
        {
            ans = st.top().first + ans;
            st.pop();
        }
        return ans;
    }
};