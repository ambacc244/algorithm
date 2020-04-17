class Solution {
  public int solution(int n) {
      int answer = 0;
      int[] array = new int[n+1];

      for(int i=0; i<array.length; i++)
          array[i] = i;

      for(int i=2; i<array.length; i++)
          if(array[i] != 0)
              for(int j=i+array[i]; j<array.length; j+=array[i])
                  array[j] = 0;

      for(int i=2; i<array.length; i++)
          if(array[i] != 0)
              answer++;

      return answer;
  }
}
