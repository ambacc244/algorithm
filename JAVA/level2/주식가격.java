class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];

        for(int i=0; i<prices.length-1; i++){
            int index = 1;
            for(int j=i+1; j<prices.length-1; j++){
                if(prices[i] <= prices[j]){
                    index++;
                }
                else
                    break;
            }
            answer[i] = index;
        }
        answer[prices.length-1] = 0;

        return answer;
    }
}
