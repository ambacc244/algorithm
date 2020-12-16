function passArray(pass){
    for(let i of pass)
        if(!i)
            return false;
    return true;
}

function solution(name) {
    var answer = 0;
    let SIZE = name.length;
    let pass = new Array(SIZE).fill(false);
    let left;
    let right;
    let current = 0;

    for(let i=0; i<SIZE; i++){
        answer += Math.min(91-name[i].charCodeAt(0), name[i].charCodeAt(0)-65)
        
        if(name[i] === 'A')
             pass[i] = true;
    }

    while(!passArray(pass)){
        left = 0;
        right = 0;
        
        for(let i=0; i<SIZE; i++)
            if(pass[(current+i)%SIZE])
                right++;
            else 
                break;

        for(let i=0; i<SIZE; i++)
            if(pass[(SIZE+current-i)%SIZE])
                left++;
            else 
                break;
        
        if(left >= right){
            answer += right;
            current = (current+right)%SIZE;
        }
        else{
            answer += left;
            current = (SIZE+current-left)%SIZE;
        }
        pass[current] = true;
    }
    
    return answer;
}