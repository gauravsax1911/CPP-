#include <bits/stdc++.h>
using namespace std;
int mazepath_multijump_recursive(int sr, int sc, int er, int ec, vector<vector<int>> &dir, int n, int m, vector<string> &dirS, vector<vector<string>> &ans, string psf, int jumps)
{
    if (sr == er && sc == ec)
    {
        return 1;
    }
    int count = 0;
    for (int d = 0; d < dir.size(); d++)
    {
        for (int rad = 1; rad < max(n, m); rad++)
        {
            int r = sr + rad * dir[d][0];
            int c = sc + rad * dir[d][1];

            if (r >= 0 && c >= 0 && r < n && c < m)
            {
                count += mazepath_multijump_recursive(r, c, er, ec, dir, n, m, dirS, ans, psf + dirS[d], jumps + 1);
            }
            else
            {
                break;
            }
        }
    }

    return count;
}

int main()
{
    int n, m;
    n = 3;
    m = 3;
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {1, 1}};
    vector<string> dirS = {"r", "d", "b"};
    vector<vector<string>> ans;
    vector<vector<int>> dp(n, std::vector<int>(m, 0));
    cout << "RECURSIVE ANSWER----->  " << mazepath_multijump_recursive(0, 0, n - 1, m - 1, dir, n, m, dirS, ans, "", 0) << endl;
}