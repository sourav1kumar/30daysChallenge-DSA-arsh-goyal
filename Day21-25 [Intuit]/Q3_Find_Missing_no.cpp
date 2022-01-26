/*
    Given a string consisting of some numbers, not separated by any separator. The numbers are positive integers and the sequence increases by one at each number except the missing number. The task is to complete the function missingNumber which return's the missing number. The numbers will have no more than six digits. Print -1 if input sequence is not valid.

    Input:
    2
    9899100102
    1112141519

    Output:
    101
    -1

*/
int missingNumber(const string &str)
{
    int n = str.size(), missing = -1;

    for (int l = 1; l <= 6; ++l)
    {
        if (l > n || missing != -1)
            break;

        int prev = stoi(str.substr(0, l)), len = l;

        for (int i = len; i <= n - len;)
        {

            int tmp = stoi(str.substr(i, len));
            if (tmp == prev + 1)
            {
                prev = tmp;
                i += len;
                continue;
            }
            else if (tmp == prev + 2 && missing == -1)
            {
                prev = tmp;
                missing = tmp - 1;
                i += len;
                continue;
            }
            if (i + len >= n || (to_string(prev + 2).size() == len))
            {
                missing = -1;
                break;
            }
            else
                len++;
            tmp = stoi(str.substr(i, len));

            if (tmp == prev + 1)
            {
                prev = tmp;
                i += len;
            }
            else if (tmp == prev + 2 && missing == -1)
            {
                prev = tmp;
                missing = tmp - 1;
                i += len;
            }
            else
            {
                missing = -1;
                break;
            }
        }
    }
    return missing;
}