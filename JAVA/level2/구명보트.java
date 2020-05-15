import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        Deque<Integer> cache = new ArrayDeque<Integer>();

        Arrays.sort(people);

        for(int i : people)
            cache.add(i);

        while(!cache.isEmpty()){
            if(cache.size() == 1 || cache.peekFirst() + cache.peekLast() > limit)
                cache.pollLast();
            else{
                int sum = limit - cache.pollFirst() - cache.pollLast();

                while(!cache.isEmpty() && sum - cache.peekFirst() >= 0)
                    sum -= cache.pollFirst();
            }
            answer++;
        }

        return answer;
    }
}
