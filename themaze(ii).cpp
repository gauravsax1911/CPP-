#include <bits/stdc++.h>
using namespace std;
class pair_{
    public:
    int idx;
    int dsf;

    pair_(int idx,int dsf)
    {
        this->idx = idx;
        this->dsf = dsf;
    }

};

struct comp{
    bool operator()(pair_ &a, pair_ &b)
    {
        return a.dsf > b.dsf;
    }
};


int shortestDistance_helper(vector<vector<int>> &maze, int sr, int sc, int er,int ec)
{ 
    int n = maze.size();
    int m = maze[0].size();

    priority_queue<pair_ , vector<pair_> , comp> pq;
    vector<vector<bool>> vis(n,std::vector<bool>(m,false));
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

    pq.push(pair_(sr*m + sc,0));
    vis[sr][sc] = true;
    while(pq.size() != 0)
    {
        pair_ p = pq.top();
        pq.pop();
        int idx = p.idx;
        int psf = p.dsf;
        int i = idx/m;
        int j = idx%m;
        
        for(int d = 0;d<dir.size();d++)
        {   int steps = -1;
            int r = i;
            int c = j;
            while(r>=0 && c>=0 && r<n && c<m && maze[r][c] == 0)
            {
                r += dir[d][0];
                c += dir[d][1];
                steps++;
            }
            r -= dir[d][0];
            c -= dir[d][1];
            steps--;

            if(vis[r][c])
            {continue;}

            if(r == er && c == ec)
            {
                 return psf + steps;

            }

            vis[r][c] = true;

            pq.push(pair_(r*m + c, psf + steps));


        }
 

    }

   return -1;
}



int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
{

    int sr = start[0];
    int sc = start[1];

    int er = destination[0];
    int ec = destination[1];

    int ans = shortestDistance_helper(maze,sr,sc,er,ec);
}

int main()
{
}