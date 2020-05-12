import java.lang.*;

class Solution {
    public long solution(long n) {
        long answer = 0;

        if(n == (long)(Math.pow((long)Math.sqrt(n), 2)))
           return (long)Math.pow(((long)Math.sqrt(n)+1), 2);
        return -1;
    }
}
