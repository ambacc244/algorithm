function numberSort(a, b){
    a = a.toString();
    b = b.toString();
    
    return Number(b+a) - Number(a+b);
}

function solution(numbers) {
    var answer = '';
    
    numbers.sort(numberSort);
    
    answer = numbers.reduce((p, c)=>{
        return p+c;
    },'')
    
    if(answer[0] === '0')
        return '0';
    return answer;
}