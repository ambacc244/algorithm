function solution(n) {
    var answer = '';
    
    while(n > 0){
        if(n%3 === 1){
            answer = "1" + answer;
            n = (n - n%3)/3;
        }
        else if(n%3 === 2){
            answer = "2" + answer;
            n = (n - n%3)/3;
        }
        else if(n%3 === 0){
            answer = "4" + answer;
            n = (n - 3)/3;
        }
    }
    
    return answer;
}