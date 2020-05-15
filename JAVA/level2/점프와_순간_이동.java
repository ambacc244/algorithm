import java.util.*;

public class Solution {
    public int solution(int n) {
        int ans = 0;
        int val;

        while(n != 0){
            val = 1;

            while(val*2 <= n)
                val *= 2;

            ans++;
            n -= val;
        }

        return ans;
    }
}
