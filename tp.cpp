#include <bits/stdc++.h>
using namespace std;
void pattern(int n)
{
    int mid = n / 2;
    vector<vector<string>> grid(n, std::vector<string>(mid + 1, " "));
    for (int i = 0; i < mid + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int r = i;
            int rangepos = mid + r;
            int rangeneg = mid - r;

            for (int k = rangeneg; k <= rangepos; k++)
            {
                grid[i][k] = "*";
            }
        }
    }

    for (vector<string> s : grid)
    {
        for (string c : s)
        {
            cout << c << " ";
        }
    }
}
int main()
{
    int n = 7;
    pattern(n);
}