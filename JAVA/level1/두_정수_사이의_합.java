import java.util.*;

class Solution {
  public long solution(int a, int b) {
      long answer = 0;
      long interval = a - b;

      if(interval == 0)
        return a;

      if(interval <-1)
        interval *= -1;

      if(interval%2 == 1)
          return (long)(a+b)*(interval+1)/2;

      return (long)(a+b)*(interval)/2 + (a+b)/2;
  }
}
