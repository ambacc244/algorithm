class Solution {
  public String solution(String[] seoul) {
      String answer = "";

      for(int i=0; i<seoul.length; i++)
          if(seoul[i].compareTo("Kim") == 0)
              return "김서방은 " + Integer.toString(i) + "에 있다";

      return answer;
  }
}
