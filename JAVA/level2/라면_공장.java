import java.util.*;

class Solution {
    public int solution(int stock, int[] dates, int[] supplies, int k) {
        int answer = 0;
        PriorityQueue<Integer> cache = new PriorityQueue<Integer>(Collections.reverseOrder());
        int day = stock;
        int index = 0;

        while(day < k){
            for(int i=index; i<dates.length; i++){
                if(dates[i] <= day)
                    cache.add(supplies[i]);
                else{
                    index = i;
                    break;
                }

                if(i == dates.length-1)
                    index = i+1;
            }

            int temp = cache.poll();
            day += temp;
            System.out.println(day);
            answer++;
        }

        return answer;
    }
}
