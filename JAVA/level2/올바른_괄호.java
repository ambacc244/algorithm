class Solution {
    boolean solution(String s) {
        char[] chars = s.toCharArray();
        int num = 0;

        for(char c : chars){
            if(c == '(')
                num++;
            if(c == ')')
                num--;

            if(num < 0)
                return false;
        }

        if(num != 0)
            return  false;
        return true;
    }
}
