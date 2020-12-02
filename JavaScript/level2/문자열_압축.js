function solution(s) {
    var answer = s.length;
    
    for(let i=1; i<=s.length/2; i++){
        let str = "";
        let tocken = s.substring(0, i);
        let count = 1;
        
        for(let j=i; j<s.length; j=j+i){
            if(tocken == s.substring(j, j+i))
                count++;
            else{
                if(count === 1)
                    str += tocken;
                else
                    str += (count.toString() + tocken);
            
                tocken = s.substring(j, j+i);
                count = 1;
            }
        }

        if(count === 1)
            str += tocken;
        else
            str += (count.toString() + tocken);

        answer = Math.min(answer, str.length);
    }
    
    return answer;
}