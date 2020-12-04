function solution(cacheSize, cities) {
    var answer = 0;
    let cache = [];
    
    if(cacheSize === 0)
        return cities.length*5;
    
    for(let i of cities){
        i = i.toUpperCase();
        if(cache.includes(i)){
            answer += 1;
            cache.splice(cache.indexOf(i), 1);
            cache.push(i);
        }
        else{
            answer += 5;
            if(cache.length >= cacheSize)
                cache.shift();
            cache.push(i);
        }
    }
    
    return answer;
}