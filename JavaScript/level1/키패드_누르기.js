function distance(arr1, arr2){
    return Math.abs(arr1[0] - arr2[0]) + Math.abs(arr1[1] - arr2[1]);
}

function solution(numbers, hand) {
    var answer = '';
    let left = [0, 3];
    let right = [2, 3];
    let pad = {1:[0, 0], 2:[1, 0], 3:[2, 0], 4:[0, 1], 5:[1, 1], 6:[2, 1], 7:[0, 2], 8:[1, 2], 9:[2, 2], 0:[1, 3],} 
    
    function useLeft(location){
        answer += "L";
        left[0] = location[0];
        left[1] = location[1];
    }
    
    function useRight(location){
        answer += "R";
        right[0] = location[0];
        right[1] = location[1];
    }
    
    for(let i of numbers){
        let location = pad[i.toString()];  
        
        if(i === 1 || i === 4 || i === 7)
             useLeft(location);
        else if(i === 3 || i === 6 || i === 9)
             useRight(location)
        else if(distance(left, location) === distance(right, location)){
            if(hand === "left")
                useLeft(location);
            else
                 useRight(location);
        }
        else if(distance(left, location) < distance(right, location))
            useLeft(location);
        else
            useRight(location);
        
    }

    return answer;
}