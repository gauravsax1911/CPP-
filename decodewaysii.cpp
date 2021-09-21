#include <bits/stdc++.h>
using namespace std;

int decodeways2(string s, int idx)
{
    if (idx == s.length())
    {
        return 1;
    }

    char ch = s[idx];
    int count = 0;
    if (ch == '0')
    {
        return 0;
    }
    if (s[idx] == '*')
    {
        for (int i = 1; i <= 9; i++)
        {
            string s1 = "";
            s1 = s;
            s1[idx] = 48 + i;
            count += decodeways2(s1, idx);
        }
        return count;
    }
    
    count += decodeways2(s, idx + 1);

    if (idx < s.length() - 1)
    {
        char ch1 = s[idx + 1];
        if (ch1 != '*')
        {
            int num = (ch - '0') * 10 + (ch1 - '0');
            if (num <= 26)
            {
                count += decodeways2(s, idx + 2);
            }
        }

        else
        {
            for (int i = 1; i <= 9; i++)
            {
                string s2 = s;
                s2[idx + 1] = 48 + i;
                int num = (ch - '0') * 10 + (i);
                if (num <= 26)
                {
                    count += decodeways2(s2, idx + 2);
                }
            }
        }
    }
    
    return count;
}

int main()
{
    string s = "2*";
    cout << decodeways2(s, 0);
}