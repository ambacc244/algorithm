function solution(n, t, m, p) {
    var answer = '';
    let stringVal = "";
    let val = 0;
    
    while(stringVal.length < t*m){
        stringVal += val.toString(n);
        val++;
    }
    
    stringVal = stringVal.toUpperCase()
    
    for(let i=0; i<t; i++)
       answer += stringVal[i*m+p-1];
    
    return answer;
}
