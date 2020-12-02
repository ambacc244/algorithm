function solution(bridge_length, weight, truck_weights) {
    let answer = 0;
    let total_weight = 0;
    let turck_on_bridge = [];
    let time_to_stay = [];
    
    while(!(turck_on_bridge.length === 0 && truck_weights.length === 0)){
        if(truck_weights.length !== 0)
            if(truck_weights[0]+total_weight <= weight){
                total_weight += truck_weights[0];
                turck_on_bridge.push(truck_weights[0]);
                time_to_stay.push(bridge_length);
                truck_weights.shift();
            }

        time_to_stay = time_to_stay.map((i) => i-1);
  
        if(time_to_stay[0] === 0){
            time_to_stay.shift();
            total_weight -= turck_on_bridge[0];
            turck_on_bridge.shift();
        }
        answer++;
    }
    
    return answer+1;
}