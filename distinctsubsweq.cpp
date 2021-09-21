#include <bits/stdc++.h>
using namespace std;

int distinctsubseq(string s, string t, int i, string psf, int level)
{
    if (level == t.length())
    {
        if (psf == t)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int count = 0;
    while (i < s.length())
    {
        if (s[i] == t[level])
        {
            count += distinctsubseq(s, t, i + 1, psf + s[i], level + 1);
        }
        i++;
    }

    return count;
}

int distinctsubdeq_dp_memo(string s, string t, int i, int j, vector<vector<int>> &dp)
{
    if (j == t.length())
        return 1;

    if (i == s.length())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int count1 = 0, count2 = 0;
    if (s[i] == t[j])
    {
        count2 = distinctsubdeq_dp_memo(s, t, i + 1, j + 1, dp);
    }

    count1 = distinctsubdeq_dp_memo(s, t, i + 1, j, dp);
    return dp[i][j] = count1 + count2;
}

int distinctsubseq_dp_tabu(string s, string t, int I, int J)
{
    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for (int i = s.length(); i >= I; i--)
    {
        for (int j = t.length(); j >= J; j--)
        {
            if (j == t.length())
            {
                dp[i][j] = 1;
                continue;
            }
            if ((n-i)<(m-j))
            {
                dp[i][j] = 0;
                continue;
            }
            int count1 = 0, count2 = 0;
            if (s[i] == t[j])
            {
                count1 = dp[i + 1][j + 1];
            }
            count2 = dp[i + 1][j];
            dp[i][j] = count1 + count2;
        }
    }
    return dp[I][J];
}

int main()
{
    string s = "babgbag", t = "bag";
    int ans = distinctsubseq_dp_tabu(s,t,0,0);
    cout << ans;
}