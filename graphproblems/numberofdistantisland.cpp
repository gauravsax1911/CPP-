void dfs_island(vector<vector<int>> &graph, int i , int j , vector<vector<int>> &dir, vector<string> &ds , string &s)
{
    graph[i][j] = 0;
    int n = graph.size();
    int m = graph[0].size();
    for(int d=0;d<dir.size();d++)
    {
        int r = i + dir[d][0];
        int c = j + dir[d][1];

        if(r>=0 && c>=0 && r<n && c<m && graph[r][c] == 1)
        {
            s += ds[d];
            dfs_island(graph,r,c,dir,ds,s);
        }
    }

    s += "b";
}



int numberofDistinctIslands(vector<vector<int>> &grid)
{
    vector<vector<int>> dir = {{1,0} , {0,1} , {-1,0} ,{0,-1}};
    vector<string> d = {"d" , "r" , "u" , "l"};
    set<string> s ;
    int n = grid.size();
    int m = grid[0].size();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == 1)
            { 
                string x = "";
                dfs_island(grid,i,j,dir,d,x);
                s.push(x);

            }
        }
    }

    return s.size();
}