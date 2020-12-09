function solution(arr1, arr2) {
    var answer = [];
    
    for(let i=0; i<arr1.length; i++){
        let temp = [];
        for(let k=0; k<arr2[0].length; k++){
            let val = 0;
            for(let j=0; j<arr2.length; j++)
                val += (arr1[i][j] * arr2[j][k]);
            temp.push(val);
        }
        answer.push(temp);
    }
    
    return answer;
}