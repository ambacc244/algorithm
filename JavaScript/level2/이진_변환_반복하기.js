function solution(s) {
    let count = 0;
    let num0 = 0;
 
    while(s !== "1"){
        num0 += (s.length - s.match(/1/g).length);
        s = s.match(/1/g).length.toString(2);
        count++;
    }

    return [count, num0];
}