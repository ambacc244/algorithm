import java.util.*;

class Solution {
    public int[] solution(int[] heights) {
        int[] answer = new int[heights.length];
        Stack<Integer> stack = new Stack<Integer>();
        answer[0] = 0;
        stack.push(10000 + heights[0]);

        for(int i=1; i<heights.length; i++){
            Stack<Integer> temp = stack;

            while(!temp.empty()){
                if(heights[i] < stack.peek()%10000 ){
                    answer[i] = stack.peek()/10000;
                    break;
                }
                temp.pop();
            }

            if(temp.empty())
                answer[i] = 0;

            stack.push((i+1)*10000 + heights[i]);
        }

        return answer;
    }
}
