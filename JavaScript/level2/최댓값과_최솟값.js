function sortNumber(a, b){
    return a-b;
}

function solution(s) {
    let arr = [];
    let val = "";
    
    for(let i of s){
        if(i === " "){
            arr.push(Number(val));
            val = "";
        }
        else
            val += i;
    }
    arr.push(Number(val));
    arr.sort(sortNumber);
    
    return String(arr[0]) + " " + String(arr[arr.length-1]);
}