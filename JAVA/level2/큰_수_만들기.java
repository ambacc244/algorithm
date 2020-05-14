class Solution {
    public String solution(String number, int k) {
        String answer = "";

        while(k != 0){
            if(number.length() == k)
                return answer;

            int maxVal = -1;
            int index = -1;

            for(int i=0; i<=k; i++){
                if(maxVal < number.charAt(i) - '0'){
                    maxVal = number.charAt(i) - '0';
                    index = i;
                }
            }
            answer += number.charAt(index);
            number = number.substring(index+1);
            k -= index;
        }

        if(number.length() != 0)
            answer += number;

        return answer;
    }
}
