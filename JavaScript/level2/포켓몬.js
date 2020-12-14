function solution(nums) {
    
    let num = nums.filter((v, i) => nums.indexOf(v) === i);

    if(num.length <= nums.length/2)
        return num.length;
    return nums.length/2;
}
