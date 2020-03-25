#include <string>
#include <vector>

using namespace std;

int def(vector<int> numbers, int target, int val, int deep){
    if(deep >= numbers.size()){
        if(val == target)
            return 1;
        else
            return 0;
    }
    else{
        return def(numbers, target, val+numbers[deep], deep+1) + def(numbers, target, val-numbers[deep], deep+1);
    }
}

int solution(vector<int> numbers, int target) {
    return def(numbers, target, numbers[0], 1) + def(numbers, target, numbers[0]*(-1), 1);
}
