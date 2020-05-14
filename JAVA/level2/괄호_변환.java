class Solution {

    public String calculate(String p){
        if(p.equals(""))
            return "";

        int left = 0;
        int right = 0;
        int index = 0;
        boolean pass = true;

        for(int i=0; i<p.length(); i++){
            if(p.charAt(i) == '(')
                left++;
            if(p.charAt(i) == ')')
                right++;
            if(left < right)
                pass = false;
            if(left != 0 && left == right){
                index = i;
                break;
            }
        }

        if(pass == true)
            return p.substring(0, index+1) + calculate(p.substring(index+1));

        String str = p.substring(1, index);
        String temp = "";

        for(int i=0; i<str.length(); i++){
            if(str.charAt(i) == '(')
                temp += ")";
            if(str.charAt(i) == ')')
                temp += "(";
        }

        return ("("+ calculate(p.substring(index+1)) + ")" + temp);
    }

    public String solution(String p) {
        return calculate(p);
    }
}
