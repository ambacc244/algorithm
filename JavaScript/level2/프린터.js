function compareNumbers(a, b) {
    return b - a;
}

function solution(priorities, location) {
    var answer = 0;
    let order = priorities.map((val, index) => [val, index]);

    priorities.sort(compareNumbers);
    
    while(order.length !== 0){
        if(order[0][0] === priorities[0]){
            answer++;
            if(order[0][1] === location)
                break;
            order.shift();
            priorities.shift();
        }
        else{
            let temp = order.shift();
            order.push(temp);
        }
    }
    
    return answer;
}