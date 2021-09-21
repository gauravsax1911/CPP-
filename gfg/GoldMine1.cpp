// Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxgold_recursive(int i, int j, vector<vector<int>> &M, int psf, int n, int m)
    {

        if (i < 0 || i >= n || j >= m)
        {
            return psf;
        }

        return max(maxgold_recursive(i + 1, j + 1, M, psf + M[i][j], n, m), max(maxgold_recursive(i, j + 1, M, psf + M[i][j], n, m), maxgold_recursive(i - 1, j + 1, M, psf + M[i][j], n, m)));
    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> M(n, std::vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.maxGold(n, m, M) << endl;
    }

    return 0;
}