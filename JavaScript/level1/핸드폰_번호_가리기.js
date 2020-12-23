function solution(phone_number) {
    return phone_number.substring(phone_number.length-4).padStart(phone_number.length,'*');
}