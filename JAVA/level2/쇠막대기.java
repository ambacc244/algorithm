class Solution {
    public int solution(String arrangement) {
        int answer = 0;
        int sticks = 0;

        for(int i=0; i<arrangement.length(); i++){
            if(arrangement.charAt(i) == '(' && arrangement.charAt(i+1) == ')'){
                answer += sticks;
                i++;
            }
            else if(arrangement.charAt(i) == '('){
                sticks++;
            }
            else{
                sticks--;
                answer ++;
            }
        }

        return answer;
    }
}
