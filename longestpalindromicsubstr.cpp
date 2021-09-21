#include <bits/stdc++.h>
using namespace std;

class ANS
{
public:
    int size;
    int i;
    int j;

    ANS()
    {
        this->size = 1;
        this->i = 0;
        this->j = 0;
    }

    ANS(int size, int i, int j)
    {
        this->size = size;
        this->i = i;
        this->j = j;
    }
};

void longestpalindromicsubstr(string s)
{
    ANS ans;
    int n = s.length();
    int count = 0;
    vector<vector<bool>> dp(n, std::vector<bool>(n, false));
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (gap == 0)
            {
                dp[i][j] = true;
                count++;
            }
            else if (gap == 1 && s[i] == s[j])
            {
                dp[i][j] = true;
                count++;
                if (ans.size < (j - i) + 1)
                {
                    ans.size = (j - i) + 1;
                    ans.i = i;
                    ans.j = j;
                }
            }
            else
            {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                if (dp[i][j])
                {
                    count++;
                    if (ans.size < (j - i) + 1)
                    {
                        ans.size = (j - i) + 1;
                        ans.i = i;
                        ans.j = j;
                    }
                }
            }
        }
    }

    cout << "Number of Palindromic Substring: " << count << endl;
    cout << "Palindromic Substring with Maximum Size  " << ans.size << endl;
    cout << "String : " << s.substr(ans.i, (ans.j - ans.i) + 1) << endl;
}

int main()
{
    string s = "babaabad";
    longestpalindromicsubstr(s);
}