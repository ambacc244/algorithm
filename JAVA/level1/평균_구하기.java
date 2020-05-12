class Solution {
    public double solution(int[] arr) {
        double answer = 0;
        int SIZE = arr.length;
        long sum = 0;

        for(int i=0; i<SIZE; i++)
            sum += (long)arr[i];

        return (double)sum/(double)SIZE;
    }
}
