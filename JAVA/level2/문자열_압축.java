class Solution {
    public int solution(String s) {
        int answer = s.length();
        int SIZE = s.length();
        String S = s;

        for(int i=1; i<=SIZE/2; i++){
            s = S;
            String str = "";
            String end = "";

            if(SIZE%i != 0){
                end = s.substring(SIZE - SIZE%i);
                s = s.substring(0, SIZE - SIZE%i);
            }

            String token = s.substring(0, i);
            int index = 1;

            for(int j=i; j<s.length(); j+=i){
                if(token.equals(s.substring(j, j+i)))
                    index++;
                else{
                    if(index == 1)
                        str += token;
                    else
                        str += (Integer.toString(index) + token);

                    token = s.substring(j, j+i);
                    index = 1;
                }
            }

            if(index == 1)
                str += token;
            else
                str += (Integer.toString(index) + token);

            str += end;
            answer = Math.min(answer, str.length());
        }

        return answer;
    }
}
