class Solution {
    public int solution(int num) {
        int answer = 0;
        long number = (long)num;

        while(number != 1 && answer != 501){
            if(number%2 == 0)
                number /= 2;
            else
                number = number*3 + 1;
            answer++;
        }

        if(answer == 501)
            return -1;
        return answer;
    }
}
