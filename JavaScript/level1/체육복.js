function solution(n, lost, reserve) {
    let answer = 0;
    let students = new Array(n).fill(1);
    
    for(let i=0; i<lost.length; i++)
        students[lost[i]-1]--;
    
    for(let i=0; i<reserve.length; i++)
        students[reserve[i]-1]++;
    
    for(let i=0; i<students.length; i++){
        if(students[i] == 0){
            if(i !== 0 && students[i-1] > 1){
                students[i-1]--;
                answer++;
            }
            else if(i !== students.length-1 && students[i+1] > 1){
                students[i+1]--;
                answer++;
            }
        }
        else 
            answer++;
    }
    
    return answer;
}