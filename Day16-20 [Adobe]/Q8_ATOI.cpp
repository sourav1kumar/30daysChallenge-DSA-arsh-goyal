/*
    Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.

    Note: You are not allowed to use inbuilt function.

    Example 1:

    Input:
    str = 123
    Output: 123
*/
class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string str)
    {
        int tmp = 0, n = str.size();
        int i = 0, neg = 0;
        if (str[0] == '-')
            i++, neg = 1;

        for (; i < n; ++i)
        {
            if (str[i] >= '0' && str[i] <= '9')
                tmp = tmp * 10 + (str[i] - '0');
            else
                return -1;
        }
        if (neg)
            tmp = -tmp;
        return tmp;
    }
};