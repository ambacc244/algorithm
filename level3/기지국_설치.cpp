#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    int current = 0;

    sort(stations.begin(), stations.end());

    for(int i=0; i<stations.size(); i++){
        while(current < stations[i]-w-1){
            current = current + w*2 +1;
            answer++;
        }
        current = stations[i]+w;
    }

    if(current < n){
        if((n - current)%(w*2+1) == 0)
            answer += (n - current)/(w*2+1);
        else
            answer += (n - current)/(w*2+1)+1;
    }
    return answer;
}
