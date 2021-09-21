#include <bits/stdc++.h>
using namespace std;

int deleteoptomakeequal(string s1, string s2, int i, int j)
{
    if (i == s1.length() || j == s2.length())
    {

        return i == s1.length() ? (s2.length() - j) : (s1.length() - i);
    }

    if (s1[i] == s2[j])
    {
        return deleteoptomakeequal(s1, s2, i + 1, j + 1);
    }
    else
    {

        int c1 = deleteoptomakeequal(s1, s2, i + 1, j) + 1;
        int c2 = deleteoptomakeequal(s1, s2, i, j + 1) + 1;
        return min(c1, c2);
    }
}

int deleteoptomakeequal_dp_memo(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if (i == s1.length() || j == s2.length())
    {

        return dp[i][j] = (i == s1.length()) ? (s2.length() - j) : (s1.length() - i);
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
    {
        return dp[i][j] = deleteoptomakeequal_dp_memo(s1, s2, i + 1, j + 1, dp);
    }
    else
    {

        int c1 = deleteoptomakeequal_dp_memo(s1, s2, i + 1, j, dp) + 1;
        int c2 = deleteoptomakeequal_dp_memo(s1, s2, i, j + 1, dp) + 1;
        return dp[i][j] = min(c1, c2);
    }
}

int deleteoptomakeequal_dp_tabu(string s1, string s2, int i, int j)
{
    vector<vector<int>> dp(502, std::vector<int>(502, -1));
    for (int j = s2.length(); j >= 0; j--)
    {
        for (int i = s1.length(); i >= 0; i--)
        {

            if (i == s1.length() || j == s2.length())
            {

                dp[i][j] = (i == s1.length()) ? (s2.length() - j) : (s1.length() - i);
                continue;
            }

            if (s1[i] == s2[j])
            {
                dp[i][j] = dp[i + 1][j + 1]; //deleteoptomakeequal_dp_memo(s1, s2, i + 1, j + 1, dp);
            }
            else
            {

                int c1 = dp[i + 1][j] + 1; //deleteoptomakeequal_dp_memo(s1, s2, i + 1, j, dp) + 1;
                int c2 = dp[i][j + 1] + 1; //deleteoptomakeequal_dp_memo(s1, s2, i, j + 1, dp) + 1;
                dp[i][j] = min(c1, c2);
            }
        }
    }

    return dp[i][j];
}

int main()
{
    string s1 = "leetcode", s2 = "etco";
    cout << deleteoptomakeequal_dp_tabu(s1, s2,0,0);
}