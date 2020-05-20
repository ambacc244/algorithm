class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        int sum = (brown -4)/2;
        int mul = yellow;

        for(int i=1; i<=sum/2; i++)
            if(mul == i*(sum-i)){
                answer[0] = sum-i+2;
                answer[1] = i+2;
                break;
            }

        return answer;
    }
}
