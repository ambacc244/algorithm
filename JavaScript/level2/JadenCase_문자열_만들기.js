function solution(s) {
    var answer = '';
    
    for(let i=0; i<s.length; i++){
        if(i === 0 && ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
            answer += s[i].toUpperCase();
        else if(i !== 0 && s[i-1] === " " && ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
            answer += s[i].toUpperCase();
        else if(s[i] >= 'A' && s[i] <= 'Z')
            answer += s[i].toLowerCase();
        else
            answer += s[i];   
    }
 
    return answer;
}
