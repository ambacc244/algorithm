#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int total_weight = 0;
    vector<int> truck_on_bridge;
    int bridge[bridge_length];
    int temp;

    for(int i=0; i<bridge_length; i++)
        bridge[i] = 0;

    while(truck_weights.size() != 0){

        if(bridge[bridge_length-1] != 0){
            total_weight -= truck_on_bridge[0];
            truck_on_bridge.erase(truck_on_bridge.begin());
        }

        for(int i=bridge_length-1; i>0; i--)
            bridge[i] = bridge[i-1];

        bridge[0] = 0;

        if(total_weight + truck_weights[0] <= weight){
            total_weight += truck_weights[0];
            truck_on_bridge.push_back(truck_weights[0]);
            bridge[0] = truck_weights[0];
            truck_weights.erase(truck_weights.begin());
        }
        answer++;
    }

    int index = bridge_length;

    for(int i=0; i<bridge_length; i++)
        if(bridge[i] != 0 ){
            index = i;
            break;
        }
        
    return answer+(bridge_length-index);
}
