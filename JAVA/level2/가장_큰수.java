import java.util.*;

class Solution {

    public String solution(int[] numbers) {
        String answer = "";
        String [] strings = new String[numbers.length];

        for(int i=0; i<numbers.length; i++)
            strings[i] = Integer.toString(numbers[i]);

        Arrays.sort(strings, new Comparator<String>() {
            @Override
            public int compare(String str1, String str2) {
                return (str1+str2).compareTo(str2+str1);
            }
        });

        for(int i=0; i<numbers.length; i++)
            answer = strings[i] + answer;

        if(answer.charAt(0) == '0')
            return "0";
        return answer;
    }
}
