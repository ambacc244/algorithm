class Solution {

    public int calcualte(int n, int a, int b){
        if(n == 2)
            return (a+b)%1234567;
        return calcualte(n-1, b%1234567, (a+b)%1234567);
    }

    public int solution(int n) {
        int answer = 0;
        int first = 0;
        int second = 1;

        if(n == 0)
            answer = 0;
        else if(n == 1)
            answer = 1;
        else
            answer = calcualte(n, 0, 1);

        return answer;
    }
}
