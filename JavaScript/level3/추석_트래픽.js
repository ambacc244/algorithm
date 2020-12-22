function solution(lines) {
    var answer = 0;
    let start = [];
    let end = [];
    
    for(let i of lines){
        let array = i.split(" ");
        let times = array[1].split(":");
        let eTime = Number(times[0])*60*60 + Number(times[1])*60 + Number(times[2]);
        end.push(Number(times[0])*60*60 + Number(times[1])*60 + Number(times[2]));
        start.push(eTime - Number(array[2].substring(0, array[2].length-1)) + 0.001);
    }
    
    for(let t of end){
        let val = 0;
        let s = t;
        let e = (t + 0.999).toFixed(3);
        
        for(let i=0; i<end.length; i++){
            if((start[i] <= s && end[i] >= e) || 
               (end[i] >= s && end[i] <= e) || 
               (start[i] >= s && start[i] <= e)
              )
                val++;
        }
        answer = Math.max(answer, val);
    }
    
    return answer;
}