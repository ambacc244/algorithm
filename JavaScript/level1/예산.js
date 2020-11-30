function numberSort(a, b){
    return a-b;
}

function solution(d, budget) {
    var answer = 0;
    
    d.sort(numberSort);
  
    for(let i=0; i<d.length; i++){
        if(budget-d[i]>=0)
            budget -= d[i];
        else 
            return i;
    }
    
    return d.length;
}