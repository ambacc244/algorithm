import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        int[] answer = {};
        int[] temp = new int[arr.length];
        int index = 0;

        System.arraycopy(arr, 0, temp, 0, arr.length);

        if(arr.length == 1){
            answer = new int[1];
            answer[0] = -1;
            return answer;
        }

        answer = new int[arr.length-1];

        Arrays.sort(temp);

        for(int i=0; i<arr.length; i++){
            if(temp[0] != arr[i]){
                answer[index] = arr[i];
                index++;
            }
        }

        return answer;
    }
}
