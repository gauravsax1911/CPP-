int findpar(int p,vector<int> par)
{
    return par[p] == p ? p : (par[p] = findpar(par[p],par));
}


vector<int> numIslands2(int n, int m, vector<Point> &operators)
{
    vector<vector<int>> waterisland(n, std::vector<int>(m, 0));
    vector<int> par(n * m);
    for (int i = 0; i < n * m; i++)
    {
        par[i] = i;
    }
    int islandcount = 0;
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int k = 0; k < coordinates.size(); k++)
    {
        for (vector<int> x : coordinates[k])
        {
            int i = x[0];
            int j = x[1];

            waterisland[i][j] = 1;
            islandcount++;

            int par1 = findpar(i * m + j, par);

            for (int d = 0; d < dir.size(); d++)
            {
                int r = i + dir[d][0];
                int c = j + dir[d][1];

                if (r >= 0 && r < n && c >= 0 && c < m && waterisland[r][c] == 1)
                {
                    int par2 = findpar(r * m + c, par);

                    if (par1 != par2)
                    {
                        par[par2] = par1;
                        islandcount--;
                    }
                }
            }
        }
    }
    return islandcount;
}