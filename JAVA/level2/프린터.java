import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        int index = priorities.length-1;
        Queue<Integer> queue = new LinkedList<Integer>();

        for(int i=0; i<priorities.length; i++){
            if(location == i)
                queue.offer(priorities[i]*-1);
            else
                queue.offer(priorities[i]);
        }

        Arrays.sort(priorities);

        while(!queue.isEmpty()){
            if(queue.peek() == priorities[index] || queue.peek()*-1 == priorities[index]){
                if(queue.peek() < 0)
                    return answer+1;
                queue.poll();
                answer++;
                index--;
            }
            else{
                int temp = queue.peek();
                queue.poll();
                queue.offer(temp);
            }
        }

        return answer;
    }
}
