function compareNumber(a, b){
    return a-b;
}
function solution(n, times) {
    times.sort(compareNumber);
    let maxVal = n*times[0];
    let minVal = 0;
    let midVal;
  
    while(minVal <= maxVal){
        midVal = Math.ceil((maxVal+minVal)/2);
        let val = times.reduce((a, b) => {
            return a + Math.floor(midVal/b);
        }, 0);
    
        if(val >= n)
            maxVal = midVal-1;
        else
            minVal = midVal+1;
    }

    return minVal;
}