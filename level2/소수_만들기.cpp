#include <vector>
#include <iostream>
using namespace std;

int prime;

void isPrime(int num){
    for(int i=2; i<num/2; i++){
        if(num%i == 0)
            return;
    }
    prime++;
}

int solution(vector<int> nums) {
    prime = 0;

    for(int i=0; i<nums.size(); i++)
        for(int j=i+1; j<nums.size(); j++)
            for(int k=j+1; k<nums.size(); k++)
                isPrime(nums[i] + nums[j] + nums[k]);
    return prime;
}
