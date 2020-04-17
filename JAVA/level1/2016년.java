class Solution {
  public String solution(int a, int b) {
      int[] day = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      String[] dayWeek = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
      int date = 0;

      for(int i=0; i<a-1; i++)
          date += day[i];
      date += b;

      return dayWeek[date%7];
  }
}
