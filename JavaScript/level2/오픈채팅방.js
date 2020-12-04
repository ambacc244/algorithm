function solution(record) {
    var answer = [];
    let user = {};
    let action = [];
    
    for(let i of record){
        let temp = i.split(" ");  
        if(temp[0] === "Enter"){
            user[temp[1]] = temp[2];
            action.push([temp[0], temp[1]]);
        }
        if(temp[0] === "Leave")
            action.push([temp[0], temp[1]]);     
        if(temp[0] === "Change")
            user[temp[1]] = temp[2];
    }

    for(let i of action){
        if(i[0] === "Enter")
            answer.push(user[i[1]] + "님이 들어왔습니다.");
        if(i[0] === "Leave")
            answer.push(user[i[1]] + "님이 나갔습니다.");
    }
    
    return answer;
}