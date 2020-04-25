#include <vector>
#include <iostream>

using namespace std;

void check(int &size, int color, int m, int n, int i, int j, vector<vector<int>> &picture) {
    if(i != m-1 && picture[i+1][j] == color){
        picture[i+1][j] = 0;
        check(size, color, m, n, i+1, j, picture);
        size++;
    }

    if(j != n-1 && picture[i][j+1] == color) {
        picture[i][j+1] = 0;
        check(size, color, m, n, i, j+1, picture);
        size++;
    }

    if(i != 0 && picture[i-1][j] == color){
        picture[i-1][j] = 0;
        check(size, color, m, n, i-1, j, picture);
        size++;
    }

    if(j != 0 && picture[i][j-1] == color) {
        picture[i][j-1] = 0;
        check(size, color, m, n, i, j-1, picture);
        size++;
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer;
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(picture[i][j] != 0){
                int size = 1;
                int color = picture[i][j];

                picture[i][j] = 0;
                check(size, color, m, n, i, j, picture);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, size);
            }
        }
    }
    answer.push_back(number_of_area);
    answer.push_back(max_size_of_one_area);

    return answer;
}
