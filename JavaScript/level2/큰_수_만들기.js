function solution(number, k) {
    var answer = '';
    let start = 0;
    let selected = [];
    let size = k;
    
    while(k > 0){
        let index = start;
        let maxVal = number[start];
            for(let i=start; i<Math.min(start+k+1, number.length); i++){
                if(maxVal === '9')
                    break;
                if(maxVal < number[i]){
                    maxVal = number[i];
                    index = i;
                }
            }
        selected.push(index);
        k -= (index - start);
        start = index+1;
        if(start+k >= number.length)
            break;
    }
    
    for(let i of selected)
        answer += number[i];

    return answer+number.substring(answer.length+size);
}