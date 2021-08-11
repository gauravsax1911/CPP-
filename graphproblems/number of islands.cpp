#include<bits/stdc++.h>
using namespace std;



void dfs_islands(vector<vector<char>> &grid , int i , int j , vector<vector<int>> dir)
{
    grid[i][j] = '0';
    int m = grid.size();
    int n = grid[0].size();
    for(int k = 0;k<dir.size();k++)
    {
        int r = i + dir[k][0];
        int c = j + dir[k][1];

        if( r >=0 && r<m && c>=0 && c<n && grid[r][c] =='1')
        {
                 dfs_islands(grid,r,c,dir);
        }

    }
}


int numberofislands(vector<vector<char>> grid)
{
    int n = grid.size();
    int m = grid[0].size();

   vector<vector<int>> dir = {{1,0} , {0,1} , {-1,0} , {0,-1}};
   int component = 0;
   for(int i = 0; i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(grid[i][j] == '1')
           {
               component++;
               dfs_islands(grid,i,j,dir);
           }
       }
   }

    

}



int main()
{

}