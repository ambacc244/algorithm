function solution(n)
{
    var ans = 0;
    let val = 0;
    
    while(n != val){
        let temp = 1;
        ans++;
        while(n >= temp + val)
            temp *= 2;
        
        val += (temp/2);
    }
    
    return ans;
}