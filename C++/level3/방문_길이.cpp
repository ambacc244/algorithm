#include <string>
#include <iostream>

using namespace std;

bool pass[11][11][11][11];

int solution(string dirs) {
    int answer = 0;
    int currentX = 5;
    int currentY = 5;
    int futureX = 5;
    int futureY = 5;

    for(int a=0; a<11; a++)
        for(int b=0; b<11; b++)
            for(int c=0; c<11; c++)
                for(int d=0; d<11; d++)
                    pass[a][b][c][d] = false;

    for(int i=0; i<dirs.size(); i++){
        if(dirs[i] == 'U' && futureY != 10)
            futureY++;
        else if(dirs[i] == 'D' && futureY != 0)
            futureY--;
        else if(dirs[i] == 'L' && futureX != 0)
            futureX--;
        else if(dirs[i] == 'R' && futureX != 10)
            futureX++;

        if(!(futureX == currentX && futureY == currentY)){
            pass[currentX][currentY][futureX][futureY] = true;
            pass[futureX][futureY][currentX][currentY] = true;
        }
        currentX = futureX;
        currentY = futureY;
    }

    for(int a=0; a<11; a++)
        for(int b=0; b<11; b++)
            for(int c=0; c<11; c++)
                for(int d=0; d<11; d++)
                    if(pass[a][b][c][d] == true)
                        answer++;

	return answer/2;
}
