function sizeSort(a, b){
    return a.length - b.length;
}

function solution(s) {
    var answer = [];
    let values = []
    let temp = [];
    let val = 0;
    
    for(let i=2; i<s.length-1; i++){
        if(s[i] === '{')
            temp = [];
        else if(s[i] === '}'){
            temp.push(val);
            val = 0;
            values.push(temp);
        }
        else if(s[i] === ','){
            if(val != 0)
                temp.push(val);
            val = 0;
        }
        else{
            val *= 10;
            val += Number(s[i]);
        }
    }
    
    values.sort(sizeSort);
    answer.push(values[0][0]);
    
    for(let i=1; i<values.length; i++)
        answer.push(values[i].filter(v => !values[i-1].includes(v))[0]);
        
    return answer;
}