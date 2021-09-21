#include <bits/stdc++.h>
using namespace std;

bool helper_recursive(string s, vector<string> &dictionary, int i, int j, int n, int idx)
{
    if (i == n || j == n)
    {
        return i == n ? true : false;
    }

    string s1 = s.substr(i, idx);
    string s2 = s.substr(j, (n - j));

    vector<string>::iterator itr;
    vector<string>::iterator itr2;
    itr = std::find(dictionary.begin(), dictionary.end(), s1);
    itr2 = std::find(dictionary.begin(), dictionary.end(), s2);

    if (itr != dictionary.end() && itr2 != dictionary.end())
    {
        return true;
    }

    else if (itr == dictionary.end() && itr2 == dictionary.end())
    {
        return helper_recursive(s, dictionary, i, j + 1, n, idx + 1);
    }
    else if (itr != dictionary.end() && itr2 == dictionary.end())
    {
        return helper_recursive(s, dictionary, j, j, n, 0);
    }
    else
    {
        return false;
    }
}

bool wordBreak(string s, vector<string> &dictionary)
{
    set<string> wordDict;
    int len = 0;
    for (string str : dictionary)
    {
        wordDict.insert(str);
        int t = str.length();
        len = max(len, t);
    }

    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 0; i <= n; i++)
    {
        if (!dp[i])
        {
            continue;
        }

        for (int l = 1; l <= len && i + l <= n; l++)
        {
            string sbstr = s.substr(i,l);
            if (wordDict.find(sbstr) != wordDict.end())
            {
                dp[i+l] = true;
            }
        }
    }

    return dp[n];
}

bool wordbreak(string s, vector<string> &dictionary)
{
    int n = s.length();
    return helper_recursive(s, dictionary, 0, 0, n, 0);
}

int main()
{
    string s = "applepenapple";
    vector<string> dictionary = {"apple", "pen"};
    // cin >> s;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     string s;
    //     cin >> s;
    //     dictionary.push_back(s);
    // }

    cout << wordbreak(s, dictionary);
}