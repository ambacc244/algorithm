#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    int students[n+1];
    
    if(n == 1){
        if(lost.size() > 0)
            return 0;
        else 
            return 1;
    }
        
    for(int i=1; i<=n; i++)
        students[i] = 1;
    
    while(!lost.empty()){
        students[lost.back()]--;
        lost.pop_back();   
    }
    
    while(!reserve.empty()){
        students[reserve.back()]++;
        reserve.pop_back();   
    }

    for(int i=1; i<=n; i++){
        if(i == 1 && students[i] == 0){
            if(students[i+1] == 2){
                students[i]++;
                students[i+1]--;
            }
        }
        else if(i == n && students[i] == 0){
            if(students[i-1] == 2){
                students[i]++;
                students[i-1]--;
            }
        }
        else if(students[i] == 0){
            if(students[i-1] == 2){
                students[i]++;
                students[i-1]--;
            }
            else if(students[i+1] == 2){
                students[i]++;
                students[i+1]--;
            }
        }
    }
    
    for(int i=1; i<=n; i++)
        if(students[i] == 0)
            answer--;
        
    return answer;
}
