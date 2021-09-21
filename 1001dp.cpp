#include <bits/stdc++.h>
using namespace std;
int number_of_paths(int sr, int sc, int er, int ec, vector<vector<int>> &dir, int n)
{
    if (sr == er && sc == ec)
    {
        return 1;
    }

    int count = 0;
    for (int d = 0; d < dir.size(); d++)
    {
        int r = sr + dir[d][0];
        int c = sc + dir[d][1];

        if (r >= 0 && c >= 0 && r < n && c < n)
        {
            count += number_of_paths(r, c, er, ec, dir, n);
        }
    }

    return count;
}

int main()
{

    int n;
    cin>>n;
    vector<vector<int>> dir = {{0,1},{1,0},{1,1}};
    cout<<number_of_paths(0,0,n-1,n-1,dir,n);
}

