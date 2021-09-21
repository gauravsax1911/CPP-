#include <bits/stdc++.h>
using namespace std;

int decode_ways_recursive(string s, int idx)
{
    if (idx == s.length())
    {
        return 1;
    }

    char ch = s[idx];
    if (ch == '0')
    {
        return 0;
    }

    int count = decode_ways_recursive(s, idx + 1);

    if (idx < s.length() - 1)
    {
        char ch1 = s[idx + 1];
        int num = (ch - '0') * 10 + (ch1 - '0');
        if (num <= 26)
        {
            count += decode_ways_recursive(s, idx + 2);
        }
    }

    return count;
}

int decode_ways_dp_memo(string s, int idx, vector<int> &dp)
{
    if (idx == s.length())
    {
        dp[idx] = 1;
        return 1;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    char ch = s[idx];
    if (ch == '0')
    {
        return 0;
    }

    int count = decode_ways_dp_memo(s, idx + 1, dp);

    if (idx < s.length() - 1)
    {
        char ch1 = s[idx + 1];
        int num = (ch - '0') * 10 + (ch1 - '0');
        if (num <= 26)
        {
            count += decode_ways_dp_memo(s, idx + 2, dp);
        }
    }

    return dp[idx] = count;
}

int decode_ways_dp_tabu(string s, int IDX, vector<int> &dp)
{
    for (int idx = s.length(); idx >= IDX; idx--)
    {
        if (idx == s.length())
        {
            dp[idx] = 1;
            continue;
        }

        
        char ch = s[idx];
        if (ch == '0')
        {   dp[idx] = 0;
            continue;
        }

        int count =  dp[idx+1];      

        // decode_ways_dp_memo(s, idx + 1, dp);

        if (idx < s.length() - 1)
        {
            char ch1 = s[idx + 1];
            int num = (ch - '0') * 10 + (ch1 - '0');
            if (num <= 26)
            {
                count += dp[idx+2];
                // decode_ways_dp_memo(s, idx + 2, dp);
            }
        }

        dp[idx] = count;
    }

    return dp[IDX];
}

int decode_ways_recursive_with_ans(string s, int idx, string psf, map<int, char> map)
{
    if (idx == s.length())
    {
        cout << psf << endl;
        return 1;
    }

    char ch = s[idx];
    if (ch == '0')
    {
        return 0;
    }
    int n1 = ch - '0';
    string s1 = "";
    s1 += map[n1];
    int count = decode_ways_recursive_with_ans(s, idx + 1, psf + s1, map);

    if (idx < s.length() - 1)
    {
        char ch1 = s[idx + 1];
        int num = (ch - '0') * 10 + (ch1 - '0');
        if (num <= 26)
        {
            string s2 = "";
            s2 += map[num];
            count += decode_ways_recursive_with_ans(s, idx + 2, psf + s2, map);
        }
    }

    return count;
}

int decode_ways(string s)
{
    map<int, char> m;
    int n = s.length();
    for (int i = 0; i < 26; i++)
    {
        m[i + 1] = 65 + i;
    }
    vector<int> dp(n+1,-1);
    return decode_ways_dp_tabu(s, 0,dp);
}

int main()
{
    string s = "226";

    cout << decode_ways(s);
}