class Solution {
  public String solution(String s, int n) {
      String answer = "";
      n %= 26;

      for(int i=0; i<s.length(); i++){
          if(s.charAt(i) == ' ')
              answer += " ";
          else{
              int index = (int)s.charAt(i) + n;
              if(s.charAt(i)>=65 && s.charAt(i)<=90){
                  if(index > 90)
                      index -= 26;
              }
              else{
                  if(index > 122)
                      index -= 26;
              }
              answer += (char)index;
          }
      }

      return answer;
  }
}
