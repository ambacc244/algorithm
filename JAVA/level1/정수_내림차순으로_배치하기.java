import java.util.*;

class Solution {
  public long solution(long n) {
      long answer = 0;
      ArrayList<Integer> list = new ArrayList<Integer>();

      while(n != 0){
          long temp = n%10;
          list.add((int)temp);
          n /= 10;
      }

      Collections.sort(list);

      for(int i=list.size()-1; i>-1; i--){
          answer *= 10;
          answer += list.get(i);
      }

      return answer;
  }
}
