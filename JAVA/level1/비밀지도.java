class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];

        for(int i=0; i<n; i++){
            int val = arr1[i] | arr2[i];
            String str = "";
            for(int j=0; j<n; j++){
                if(val%2 == 1)
                    str = "#" + str;
                else
                    str = " " + str;
                val /= 2;
            }
            answer[i] = str;
        }

        return answer;
    }
}
