#include <string>
#include <vector>

using namespace std;

int gcd(int int1, int int2){
    int temp;

    if(int1 < int2)
        swap(int1, int2);

    while(int2 != 0){
        temp = int2;
        int2 = int1%int2;
        int1 = temp;
    }

    return int1;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    int gcdVal;

    for(int i=1; i<arr.size(); i++){
        gcdVal = gcd(answer, arr[i]);
        answer = answer*arr[i]/gcdVal;
    }

    return answer;
}
