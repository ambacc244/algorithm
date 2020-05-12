class Solution {
    public String solution(String phone_number) {
        String answer = "";
        String star = "**********************************";

        return star.substring(0, phone_number.length()-4) + phone_number.substring(phone_number.length()-4, phone_number.length());
    }
}
