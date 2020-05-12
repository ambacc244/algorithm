import java.lang.*;

class Solution {
    public int solution(String dartResult) {
        int answer = 0;
        int val = 0;
        int pre = 0;
        int ppre = 0;

        for(int i=0; i<dartResult.length(); i++){
            if(dartResult.charAt(i) == 'S'){
                ppre = pre;
                pre = (int)Math.pow(val, 1);
                answer += pre;
                val = 0;
            }
            else if(dartResult.charAt(i) == 'D'){
                ppre = pre;
                pre = (int)Math.pow(val, 2);
                answer += pre;
                val = 0;
            }
            else if(dartResult.charAt(i) == 'T'){
                ppre = pre;
                pre = (int)Math.pow(val, 3);
                answer += pre;
                val = 0;
            }
            else if(dartResult.charAt(i) == '*'){
                answer += ppre;
                answer += pre;
                ppre *= 2;
                pre *= 2;
            }
            else if(dartResult.charAt(i) == '#'){
                answer -= (pre*2);
                pre *= -1;
            }
            else
                val = val*10 + (dartResult.charAt(i)- '0');
        }

        return answer;
    }
}
