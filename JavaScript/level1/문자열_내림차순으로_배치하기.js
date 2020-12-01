function solution(s) {
    var answer = '';
    let array = [];
    
    for(let i=0; i<s.length; i++)
        array.push(s[i]);
    
    array.sort(function(a, b){
        return b.charCodeAt(0)-a.charCodeAt(0);
    })
    
    for(let i=0; i<array.length; i++)
        answer += array[i];
    
    return answer;
}