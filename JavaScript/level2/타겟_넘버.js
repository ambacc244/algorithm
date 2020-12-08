function check(numbers, target, index, val){
    if(index === numbers.length){
        if(val === target)
           return 1;
        return 0 ;
    }
    
    return(check(numbers, target, index+1, val+numbers[index]) + check(numbers, target, index+1, val-numbers[index]));  
}

function solution(numbers, target) {
    
    return check(numbers, target, 0, 0);
}