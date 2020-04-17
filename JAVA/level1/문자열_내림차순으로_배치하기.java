import java.util.*;

class Solution {
  public String solution(String s) {
      String answer = "";
      ArrayList<Character> upper = new ArrayList<Character>();
      ArrayList<Character> lower = new ArrayList<Character>();

      for(int i=0; i<s.length(); i++){
          if(s.charAt(i) >= 'A' && s.charAt(i) <= 'Z')
              upper.add(s.charAt(i));
          if(s.charAt(i) >= 'a' && s.charAt(i) <= 'z')
              lower.add(s.charAt(i));
      }

      Collections.sort(upper);
      Collections.sort(lower);

      for(int i=lower.size()-1; i>-1; i--)
          answer += lower.get(i);

      for(int i=upper.size()-1; i>-1; i--)
          answer += upper.get(i);

      return answer;
  }
}
