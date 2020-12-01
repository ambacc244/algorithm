function solution(answers) {
    var answer = [];
    let first = [1, 2, 3, 4, 5];
    let second = [2, 1, 2, 3, 2, 4, 2, 5];
    let third = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
    let correct1 = 0;
    let correct2 = 0;
    let correct3 = 0;
    let maxVal;

    for(let i=0; i<answers.length; i++){
        if(first[i%5] === answers[i])
            correct1++;
        if(second[i%8] === answers[i])
            correct2++;
        if(third[i%10] === answers[i])
            correct3++;
    }
    
    maxVal = Math.max(correct1, correct2, correct3);
    
    if(maxVal === correct1)
        answer.push(1);
    if(maxVal === correct2)
        answer.push(2);
    if(maxVal === correct3)
        answer.push(3);
    
    return answer;
}
