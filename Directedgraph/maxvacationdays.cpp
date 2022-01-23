#include <bits/stdc++.h>
using namespace std;


    // /**
    //  * @param flights: the airline status from the city i to the city j
    //  * @param days: days[i][j] represents the maximum days you could take vacation in the city i in the week j
    //  * @return: the maximum vacation days you could take during K weeks
    //  */
    int maxVacationDays(vector<vector<int>> &flights, vector<vector<int>> &days)
    {

        int n = flights.size();
        int k = days[0].size();

        vector<vector<int>> graph;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (flights[i][j] == 1)
                {
                    graph.push_back({i,j});
                }
                
            }
            graph.push_back({i,i});
        }
        vector<int> prev(n,-(int)1e9);
        prev[0] = 0;
        for(int i=1;i<=k;i++)
        {   vector<int> curr = prev;
            for(vector<int> vec : graph)
            {
                int u = vec[0];
                int v = vec[1];
                if(prev[u] == -(int)1e9)
                {continue;}
                if(prev[u] + days[v][i-1] > curr[v])
                {
                    curr[v] = prev[u] + days[v][i-1];
                }

            }
            prev = curr;
        }
        int maxvacadays = 0;
        for(int i=0;i<n;i++)
        { 
            maxvacadays = max(prev[i] , maxvacadays);

        }
      
        return maxvacadays;
    }

int main()
{  
    vector<vector<int>> flights = {{0,1,1},{1,0,1},{1,1,0}};
    vector<vector<int>> days  =   {{1,3,1},{6,0,3},{3,3,3}} ;

    cout<<maxVacationDays(flights,days)<<endl;
}