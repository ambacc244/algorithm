class Solution {
    public String solution(int n) {
        String answer = "";

        while(n != 0){
            if(n%3 == 0)
                answer = "4" + answer;
            if(n%3 == 1)
                answer = "1" + answer;
            if(n%3 == 2)
                answer = "2" + answer;

            if(n%3 == 0)
                n = n/3 -1;
            else
                n /= 3;
        }
        return answer;
    }
}
