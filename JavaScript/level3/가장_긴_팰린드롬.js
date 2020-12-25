function solution(s)
{
    var answer = 1;

    for(let i=1; i<s.length-1; i++){
        let temp = 1;
        for(let j=1; j<=Math.min(s.length-1-i, i-0); j++){
            if(s[i-j] ===s[i+j])
                temp += 2;
            else
                break;
        }
        answer = Math.max(answer, temp);
    }
    
    for(let i=0; i<s.length-1; i++){
        if(s[i] === s[i+1]){
            let temp = 2;
            for(let j=1; j<=Math.min(s.length-2-i, i-0); j++){
                if(s[i-j] ===s[i+1+j])
                    temp += 2;
                else
                    break;
            }
            answer = Math.max(answer, temp);
        }
    }
    
    return answer;
}