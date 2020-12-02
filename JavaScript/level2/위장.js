function solution(clothes) {
    var answer = 1;
    let cache = new Map();
    
    for(let i of clothes){
        if(cache.has(i[1]))
            cache.set(i[1], cache.get(i[1])+1);
        else
            cache.set(i[1], 1);
    }
     
    if(cache.size === 1)
        return cache.entries().next().value[1];
    
    for(let i of cache)
        answer *= (i[1]+1);
      
    return answer-1;
}