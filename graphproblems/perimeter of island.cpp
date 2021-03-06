class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();
        int onecount = 0, nbrcount = 0;
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    onecount++;
                    for (int d = 0; d < dir.size(); d++)
                    {
                        int r = i + dir[d][0];
                        int c = j + dir[d][1];

                        if (r >= 0 && r < n && c >= 0 && c < m && graph[r][c] == 1)
                        {
                            nbrcount++;
                        }
                    }
                }
            }
            return 4*onecount - nbrcount;
        }
    }
};