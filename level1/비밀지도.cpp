[200~#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> answer_num;
    string temp;
    
    for(int i=0; i<n; i++)
        answer_num.push_back(arr1[i] | arr2[i]);
    
    for(int i=0; i<n; i++){
        temp = "";
        for(int j=0; j<n; j++){
            if(answer_num[i]%2 == 1)
                temp = "#" + temp;
            else    
                temp = " " + temp;
            answer_num[i] /= 2;
        }
        answer.push_back(temp);   
    }
    
    return answer;
}
