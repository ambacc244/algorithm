#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int array[n+1][n+1];
    int count;
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            array[i][j] = 0;

    for(int i=0; i<results.size(); i++){
        array[results[i][0]][results[i][1]] = 1;
        array[results[i][1]][results[i][0]] = -1;
    }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(array[i][j] == 1)
                for(int k=1; k<=n; k++)
                    if(array[j][k] == 1){
                        array[i][k] = 1;
                        array[k][i] = -1;
                    }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(array[i][j] == -1)
                for(int k=1; k<=n; k++)
                    if(array[j][k] == -1){
                        array[i][k] = -1;
                        array[k][i] = 1;
                    }

    for(int i=1; i<=n; i++){
        count = 0;
        for(int j=1; j<=n; j++){
            if(array[i][j] != 0)
                count++;
        }
        if(count == n-1)
            answer++;
    }
    return answer;
}
