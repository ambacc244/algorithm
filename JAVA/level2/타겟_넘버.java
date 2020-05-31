class Solution {
    int answer;
    int result;
    int SIZE;

    public void calculate(int index, int val, int[] numbers){
        if(index == SIZE){
            if(val == result)
                answer++;
        }
        else{
            calculate(index+1, val+numbers[index], numbers);
            calculate(index+1, val-numbers[index], numbers);
        }
    }

    public int solution(int[] numbers, int target) {
        answer = 0;
        result = target;
        SIZE = numbers.length;

        calculate(0, 0, numbers);

        return answer;
    }
}
