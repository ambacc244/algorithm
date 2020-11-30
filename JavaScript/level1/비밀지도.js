function solution(n, arr1, arr2) {
    var answer = [];
    for(let i=0; i<n; i++){
        let temp = arr1[i] | arr2[i];
        let val = "";
        for(let i=0; i<n; i++){
            if(temp%2 === 1){
                val = "#" + val;
                temp -= 1;
            }
            else 
                val = " " + val;
            temp /= 2;
        }
        answer.push(val);
    }
    
    return answer;
}
