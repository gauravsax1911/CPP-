#include<bits/stdc++.h>
using namespace std;

bool dfs_island2(vector<vector<int>> &grid1, vector<vector<int>> &grid2,int i,int j,vector<vector<int>> &dir)
{
    grid2[i][j] = 0;
    bool ans = true;
    int n = grid1.size();
    int m = grid1[0].size();

    for(int d=0;d<dir.size();d++)
    {
        int r = i + dir[d][0];
        int c = j + dir[d][1];

        if(r>=0 && r<n && c>=0 && c<m && grid2[r][c] == 1)
        {
            ans = ans && dfs_island2(grid1,grid2,r,c,dir);
        }
    }

    return ans && grid1[i][j] == 1;

}


int countSubIslands(vector<vector<int>> &grid1,vector<vector<int>> &grid2)
{
    int n = grid1.size();
    int m = grid1[0].size();
    int count = 0;
    vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid2[i][j] == 1)
            {
                bool res = dfs_island2(grid1,grid2,i,j,dir);
                count += res == true ? 1 : 0;

            }
        }
    }
    return count;
}

int main(){
    vector<vector<int>> grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]]

}