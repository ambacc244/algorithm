function solution(strings, n) {
    var answer = [];
    var temp = [];
    
    for(let i=0; i<strings.length; i++)
        temp.push([strings[i][n], strings[i]]);  

    temp.sort();
  
    for(let i=0; i<temp.length; i++)
        answer.push(temp[i][1]); 

    return answer;
}
