function solution(n) {
    var answer = 1;
    
    for(let i=1; i<n/2; i++){
        let sum = 0;
        let index = i;
        
        while(sum < n)
            sum += index++;
        
         if(sum === n)
            answer++;
    }
    
    return answer;
}