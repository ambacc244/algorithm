import java.util.*;

public class Solution {
	public int[] solution(int []arr) {
        int[] answer = {};
        ArrayList<Integer> temp = new ArrayList<Integer>();

        temp.add(arr[0]);

        for(int i=1; i<arr.length; i++)
            if(arr[i] != arr[i-1])
                temp.add(arr[i]);

        answer = new int[temp.size()];

        for(int i=0; i<temp.size(); i++)
            answer[i] = temp.get(i);

        return answer;
	}
}
