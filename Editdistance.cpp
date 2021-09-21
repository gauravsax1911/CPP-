#include <bits/stdc++.h>
using namespace std;

int editDis(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
    {
        return dp[i][j] = (i == 0 ? j : i);
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int insert = editDis(s, t, i, j - 1, dp);
    int del = editDis(s, t, i - 1, j, dp);
    int replace = editDis(s, t, i - 1, j - 1, dp);

    if (s[i - 1] == t[j - 1])
    {
        return dp[i][j] = replace;
    }
    else
    {
        return dp[i][j] = min(min(insert, del), replace) + 1;
    }
}

// // // INSERT OPERATION HAS COST 4
// // REPLACE HAS COST 2 and
// DELETE HAS COST 1

// NOW WHAT IS THE MINIMUM COST WITH WITH YOU CAN PERFORM THE TASK
int editDis_02(string s, string t, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
    {
        int res = 0;
        if (i == 0 && j == 0)
        {
            return dp[i][j] = 0;
        }
        else if (i == 0 && j != 0)
        {
            return dp[i][j] = j * 4; //j times cost of insertion
        }
        else
        {
            return dp[i][j] = i * 1;
        }
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int insert = editDis(s, t, i, j - 1, dp) + 4;
    int del = editDis(s, t, i - 1, j, dp) + 1;
    int replace = editDis(s, t, i - 1, j - 1, dp) + 2;

    if (s[i - 1] == t[j - 1])
    {
        return dp[i][j] = replace;
    }
    else
    {
        return dp[i][j] = min(min(insert, del), replace);
    }
}

int minDistance(string word1, string word2)
{
    int n = word1.length();
    int m = word2.length();

    vector<vector<int>> dp(n + 1, std::vector<int>(m+1, -1));
    return editDis_02(word1, word2, n, m, dp);
}

int main()
{
    string word1 = "a";
    string word2 = "ab";

    cout << minDistance(word1, word2);
}