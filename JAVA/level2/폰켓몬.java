import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int size = nums.length;
        int []count = new int[200000];
        Arrays.fill(count, 0);
        int maxVal = 0;

        for(int i=0; i<size; i++)
            count[nums[i]-1]++;

        for(int i=0; i<200000; i++){
            if(count[i] != 0)
                maxVal++;
        }

        if(size/2 >= maxVal)
            return maxVal;

        return size/2;
    }
}
