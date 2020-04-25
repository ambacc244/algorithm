import java.util.*;

class Solution {
  public int[] solution(long n) {
      int[] answer = {};
      u

      while(n != 0){
          long temp = n%10;
          list.add((int)temp);
          n /= 10;
      }

      answer = new int[list.size()];

      for(int i=0; i<list.size(); i++)
          answer[i] = list.get(i);

      return answer;
  }
}
