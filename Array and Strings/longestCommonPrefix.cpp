string find(string s, string s1)
{
    int m, i;
    string s2;
    m = min(s.size(), s1.size());
    for (i = 0; i < m; i++)
    {
        if (s[i] != s1[i])
        {
            break;
        }
        else
        {
            s2.push_back(s[i]);
        }
    }
    return s2;
}
string longestCommonPrefix(string arr[], int N)
{
    if (N != 1)
    {
        string str = arr[0];
        for (int i = 1; i < N; i++)
        {
            str = find(str, arr[i]);
        }
        if (str.size() > 0)
        {
            return str;
        }
        else
        {
            return "-1";
        }
    }
    else
    {
        return arr[0];
    }
}