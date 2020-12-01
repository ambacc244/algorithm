function solution(s, n) {
    var answer = '';
    
    for(let i of s){
        if(i === ' ')
           answer += ' ';
        
        else if(i.charCodeAt(0) > 64 && i.charCodeAt(0) < 91){
            if(i.charCodeAt(0) + n > 90)
                answer += String.fromCharCode(i.charCodeAt(0)+n-26);
            else
                answer += String.fromCharCode(i.charCodeAt(0)+n);
        }
        else{
            if(i.charCodeAt(0) + n > 122)
                answer += String.fromCharCode(i.charCodeAt(0)+n-26);
            else
                answer += String.fromCharCode(i.charCodeAt(0)+n);
        }
    }
    
    return answer;
}