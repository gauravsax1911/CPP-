#include <bits/stdc++.h>
using namespace std;

int longestPalindromicSubsequence_recursive(string s)
{
    int n = s.length();
    if (n <= 1)
    {
        return n;
    }
    char si = s[0];
    char sj = s[n - 1];
    int len = 0;
    if (si == sj)
    {
        string s1 = s.substr(1, n - 2);
        len = longestPalindromicSubsequence_recursive(s1) + 2;
    }
    else
    {
        string s1 = s.substr(0, n - 1);
        string s2 = s.substr(1, n - 1);

        int include_si = longestPalindromicSubsequence_recursive(s1);
        int include_sj = longestPalindromicSubsequence_recursive(s2);

        len = max(include_si, include_sj);
    }

    return len;
}

int longestPalindromicSubsequence_dp(string s, vector<vector<int>> &dp, int i, int j)
{
    int n = s.length();
    if (n <= 1)
    {
        dp[i][j] = n;
        return n;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    char si = s[0];
    char sj = s[n - 1];
    int len = 0;
    if (si == sj)
    {
        string s1 = s.substr(1, n - 2);
        len = longestPalindromicSubsequence_dp(s1, dp, i + 1, j - 1) + 2;
    }
    else
    {
        string s1 = s.substr(0, n - 1);
        string s2 = s.substr(1, n - 1);

        int include_si = longestPalindromicSubsequence_dp(s1, dp, i, j - 1);
        int include_sj = longestPalindromicSubsequence_dp(s2, dp, i + 1, j);

        len = max(include_si, include_sj);
    }

    return dp[i][j] = len;
}
int longestPalindromicSubsequence_dp_GAP(string s, int I, int J, vector<vector<int>> &dp)
{
    int n = s.length();

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (i >= j)
            {
                dp[i][j] = (i == j ? 1 : 0);

                continue;
            }
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }

            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[I][J];
}

string longestPalindromicSubsequence_02(string s, int i, int j, vector<vector<int>> &dp)
{
    if (i >= j)
    {
        return i == j ? s[i] + "" : "";
    }

    if (s[i] == s[j])
    {
        return s[i] + longestPalindromicSubsequence_02(s, i + 1, j - 1, dp) + s[j];
    }

    else if (dp[i + 1][j] > dp[i][j - 1])
    {
        return longestPalindromicSubsequence_02(s, i + 1, j, dp);
    }

    else
    {
        return longestPalindromicSubsequence_02(s, i, j - 1, dp);
    }
}
string longestPalindromicSubsequence(string s)
{
    unordered_map<string, int> m;
    int n = s.length();
    vector<vector<int>> dp(n, std::vector<int>(n, 0));
    int x = longestPalindromicSubsequence_dp_GAP(s, 0, n - 1, dp);
    return longestPalindromicSubsequence_02(s, 0, n - 1, dp);
}

int main()
{
    string s = "abcbbad";
    cout << longestPalindromicSubsequence(s);
}