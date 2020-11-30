import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        int val = 0;
        boolean plma = true;
        ArrayList<Integer> list = new ArrayList<Integer>();

        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == ' '){
                if(plma == false)
                    val *= -1;
                list.add(val);
                val = 0;
                plma = true;
            }
            else if(s.charAt(i) == '-'){
                plma = false;
            }
            else{
                val *= 10;
                val += s.charAt(i) - '0';
            }
        }

        if(plma == false)
            val *= -1;
        list.add(val);

        Collections.sort(list);

        answer += Integer.toString(list.get(0));
        answer += ' ';
        answer += Integer.toString(list.get(list.size()-1));

        return answer;
    }
}
