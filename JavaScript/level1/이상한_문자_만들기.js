function solution(s) {
    var answer = '';
    let turn = true;
    
    for(let i of s){
        if(i === " "){
            turn = true;
            answer += " ";
        }
        else if(turn){
            turn = !turn;
            answer += i.toUpperCase();
        }
        else{
            turn = !turn;
            answer += i.toLowerCase();
        }
    }
    
    return answer;
}