function solution(s)
{
    let array = [];
    
    if(s.length%2 === 1)
        return 0;
    
    for(let i of s){
        if(array.length === 0 || array[array.length-1] !== i)
            array.push(i);
        else
            array.pop();
    }

    if(array.length === 0)
        return 1;
    return 0;
}