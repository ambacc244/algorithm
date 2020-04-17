//2d array sort
import java.util.*;

class Solution {
  public String[] solution(String[] strings, int n) {
      String[] answer = new String[strings.length];
      String[][] temp = new String [strings.length][3];

      for(int i=0; i<strings.length; i++){
          temp[i][0] = Character.toString(strings[i].charAt(n));
          temp[i][1] = strings[i];
          temp[i][2] = Integer.toString(i);
      }

      Arrays.sort(temp, new Comparator<String[]>(){
          @Override
          public int compare(String[] first, String[] second){
              int comparedTo = first[0].compareTo(second[0]);
              if (comparedTo == 0) return first[1].compareTo(second[1]);
              else return comparedTo;
          }
      });

      for(int i=0; i<temp.length; i++)
          answer[i] = strings[Integer.parseInt(temp[i][2])];

      return answer;
  }
}
