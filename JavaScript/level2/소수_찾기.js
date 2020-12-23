let cache = [];

function PrimeNumber(val){
    if(val === 0 || val === 1)
        return false;

    for(let i=2; i<=val/2; i++)
        if(val%i === 0)
            return false;
    
    return true;
}

function FindPrimrNumber(str, val){
    if(PrimeNumber(val))
        cache.push(val);
    
    for(let i=0; i<str.length; i++)
        FindPrimrNumber(str.slice(0, i) + str.slice(i+1), val*10 + Number(str[i]));
}

function solution(numbers) {
    FindPrimrNumber(numbers, 0);

    return [...new Set(cache)].length;
}