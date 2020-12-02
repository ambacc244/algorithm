function solution(progresses, speeds) {
    var answer = [];
    let current = 0;
    let cache = [];
    let index=0;
    
    for(let i=0; i<progresses.length; i++)
        cache.push(Math.ceil((100 - progresses[i])/speeds[i]));
    
    for(let i of cache){
        if(current < i){
            if(index != 0)
                answer.push(index);
            current = i;
            index = 1;
        }
        else 
            index++;
    }
    
    answer.push(index);

    return answer;
}