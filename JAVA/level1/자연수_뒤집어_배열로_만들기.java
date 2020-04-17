import java.util.*;

class Solution {
  public int[] solution(long n) {
      int[] answer = {};
      ArrayList<Integer> list = new ArrayList<Integer>();

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
