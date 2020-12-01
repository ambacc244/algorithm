function solution(a, b) {
    var answer = '';
    let months = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    let date = ['SUN', 'MON' , 'TUE', 'WED', 'THU', 'FRI', 'SAT'];
    let days = b+4;
    
    for(let i=0; i<a-1; i++)
        days += months[i];
    
    return date[days%7];
}