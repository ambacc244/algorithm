#include <string>
#include <vector>
#include <iostream>

using namespace std;

int calculate(vector<int> answers, int *student, int size){
    int correct = 0;

    for(int i=0; i<answers.size(); i++)
        if(answers[i] == student[i%size])
            correct++;

    return correct;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int student1[5] = {1, 2, 3, 4, 5};
    int student2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int student3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int *correct = new int[3];
    correct[0] = calculate(answers, student1, 5);
    correct[1] = calculate(answers, student2, 8);
    correct[2] = calculate(answers, student3, 10);
    
    int maxCorrect = max(correct[0], max(correct[1], correct[2]));
    
    for(int i=0; i<3; i++)
        if(correct[i] == maxCorrect)
            answer.push_back(i+1);
    
    return answer;
}
