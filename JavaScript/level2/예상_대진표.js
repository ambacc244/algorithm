function solution(n,a,b)
{
    var answer = 0;

    while(a !== b){
        if(a%2 === 1)
            a++;
        if(b%2 === 1)
            b++;
        a /= 2;
        b /= 2;
        answer++;
    }

    return answer;
}
