import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> list = new PriorityQueue<>();

        for(int x : scoville)
            list.add(x);

        while(list.peek() < K && list.size() > 1){
            int val = list.peek();
            list.poll();
            val += list.peek()*2;
            list.poll();
            list.add(val);
            answer++;
        }

        if(list.size() == 1 && list.peek() < K)
            return -1;
        return answer;
    }
}
