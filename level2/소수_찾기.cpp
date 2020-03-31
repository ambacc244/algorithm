#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> primeNumbers;

void findPrimeNumber(string numbers, int number){
    if(number != 0 && number != 1){
        bool Prime = true;
        for(int i=2; i<=number/2; i++){
          if(number%i == 0){
              Prime = false;
              break;
          }
        }
        if(Prime == true)
            primeNumbers.push_back(number);
    }

    for(int i=0; i<numbers.size();i++){
        string temp = numbers;
        temp.erase (temp.begin()+i);
        findPrimeNumber(temp, number*10 + (int)numbers[i]  - 48);
    }
}

int solution(string numbers) {

    findPrimeNumber(numbers, 0);
    sort(primeNumbers.begin(), primeNumbers.end());
    primeNumbers.erase(unique(primeNumbers.begin(), primeNumbers.end()), primeNumbers.end());

    return primeNumbers.size();
}
