function solution(dartResult) {
    var answer = 0;
    let prev = 0;
    let val = 0;
    
    for(let i=0; i<dartResult.length; i++){
        if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            val = parseInt(dartResult[i]);
            if(dartResult[i] === '1' && dartResult[i+1] === '0'){
                val = 10;
                i++;
            }    
        }
        else if(dartResult[i] === '*'){
            answer += (val*2 + prev); 
            prev = val*2;
            val = 0;
        }
        else if(dartResult[i] === '#'){
            answer -= val; 
            prev = -val;
            val = 0;
        }
        else{
            if(dartResult[i] === 'S')
                val = Math.pow(val, 1);  
            else if(dartResult[i] === 'D')
                val = Math.pow(val, 2);
            else if(dartResult[i] === 'T')
                val = Math.pow(val, 3);
            if(i === dartResult.length-1 || 
               (dartResult[i+1] >= '0' && dartResult[i+1] <= '9')){
                answer += val; 
                prev = val;
                val = 0;
            }
        }  
    }

    return answer;
}