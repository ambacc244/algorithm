import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = new int[2];
        String pre = words[0];
        HashMap<String, Integer> map = new HashMap<String, Integer>();

        map.put(pre, 1);

        for(int i=1; i<words.length; i++){
            String current = words[i];
            if(pre.charAt(pre.length()-1) != current.charAt(0) || map.containsKey(current)){
                answer[0] = i%n+1;
                answer[1] = i/n+1;
                break;
            }
            map.put(current, 1);
            pre = current;
        }

        return answer;
    }
}
