#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {

    int grid[n][m];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(i == 0 || j== 0)
                grid[i][j] = 1;
            else
                grid[i][j] = -1;
        }

    for(int i=0; i<puddles.size(); i++){
       grid[puddles[i][1]-1][puddles[i][0]-1] = 0;

       if(puddles[i][0] == 1)
           for(int j=puddles[i][1]; j<n; j++)
               grid[j][0] = 0;

       if(puddles[i][1] == 1)
           for(int j=puddles[i][0]; j<m; j++)
               grid[0][j] = 0;
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(grid[i][j] == -1)
                grid[i][j] = (grid[i-1][j] + grid[i][j-1])%1000000007;
        }
    }

    return grid[n-1][m-1];
}
