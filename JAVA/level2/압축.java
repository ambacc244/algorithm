import java.util.*;

class Solution {
    public int[] solution(String msg) {
        int[] answer = {};
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        ArrayList<Integer> temp_answer = new ArrayList<Integer>();
        String[] characters = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
        int index = 27;
        String current = Character.toString(msg.charAt(0));
        String next = "";

        for(int i=0; i<26; i++)
            map.put(characters[i], i+1);

        for(int i=1; i<msg.length(); i++){
            next = Character.toString(msg.charAt(i));

            if(map.containsKey(current+next))
                current += next;
            else{
                temp_answer.add(map.get(current));
                map.put(current+next, index++);
                current = Character.toString(msg.charAt(i));
            }
        }

        temp_answer.add(map.get(current));

        answer = new int[temp_answer.size()];

        for(int i=0; i<temp_answer.size(); i++)
            answer[i] = temp_answer.get(i);

        return answer;
    }
}
