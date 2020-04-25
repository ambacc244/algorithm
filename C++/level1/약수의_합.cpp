#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> numbers;
    int a = 1;
    int b = n;
    int answer = 0;
    
    while(b >= a){
        if(n%a == 0){
            numbers.push_back(a);
            
            if(a != b)
                numbers.push_back(b);
        }
        a++;
        b = n/a;
    }
    
    while(!numbers.empty()){
        answer += numbers.back();
        numbers.pop_back();
    }
    
    return answer;
}
