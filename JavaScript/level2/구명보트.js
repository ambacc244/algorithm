//효율성 시간초과
function numberSort(a, b){
    return b-a;
}

function solution(people, limit) {
    var answer = 0;
    
    people.sort(numberSort);
    
    while(people.length !== 0){
        let val = limit - people.shift();
        
        while(people[people.length-1] <= val){
            val -= people.pop();
        }
        answer++;
    }
    
    return answer;
}