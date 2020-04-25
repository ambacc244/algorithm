import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        ArrayList<Integer> temp = new ArrayList<Integer>();

        for(int i=0; i<progresses.length; i++){
            int count = 1;
            int sec = (100 - progresses[i])/speeds[i];
            if((100 - progresses[i])%speeds[i] != 0)
                sec++;

            for(int j=i+1; j<progresses.length; j++){
                int sec2 = (100 - progresses[j])/speeds[j];
                if((100 - progresses[j])%speeds[j] != 0)
                    sec2++;

                if(sec >= sec2){
                    count++;
                    i++;
                }
                else
                    break;
            }
            temp.add(count);
        }

        answer = new int[temp.size()];

        for(int i=0; i<temp.size(); i++)
            answer[i] = temp.get(i);

        return answer;
    }
}
