#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int solution(int n) {
    int answer = 0;
    int prime[n+1];
 
    for(int i=2; i<n+1; i++)
        prime[i]=0;
    
    for(int i=2; i<n+1; i++){
        if(prime[i] == 0){
            int index = i*2;
            while(index<n+1){
                prime[index]=1;
                index += i;
            }
        }
    }

    for(int i=2; i<n+1; i++)
        if(prime[i] == 0)
            answer++;

    return answer;
}
