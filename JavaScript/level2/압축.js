function solution(msg) {
    var answer = [];
    let indexMap = {A:1, B:2, C:3, D:4, E:5, F:6, G:7, H:8, I:9, J:10, K:11, L:12, M:13, N:14, O:15, P:16, Q:17, R:18, S:19, T:20, U:21, V:22, W:23, X:24, Y:25, Z:26}
    let current = msg[0];
    let next = "";
    let index = 27;
    for(let i=1; i<msg.length; i++){
        next = msg[i];
        
        if(current+next in indexMap)
            current = current+next;
        else{
            answer.push(indexMap[current]);
            indexMap[current + next] = index++;
            current = next;
        }
    }
    answer.push(indexMap[current]);

    return answer;
}