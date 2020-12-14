function solution(n, words) {
    let wordArray = [];
    let prv = words[0];
    
    for(let i=0; i<words.length; i++){
        if((i !== 0 && prv[prv.length-1] !== words[i][0]) || (wordArray.includes(words[i])))
            return [i%n+1, Math.floor(i/n)+1]
        wordArray.push(words[i]);
        prv = words[i]
    }

    return [0,0];
}
