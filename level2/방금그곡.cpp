#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
//너무 오래걸림
using namespace std;

string solution(string m, vector<string> musicinfos) {
    vector<pair<pair<int, int>, string>> songs;

    for(int n=0; n<musicinfos.size(); n++){
        string temp = musicinfos[n];

        int start = atoi(temp.substr(0,2).c_str())*60 + atoi(temp.substr(3,2).c_str());
        int end = atoi(temp.substr(6,2).c_str())*60 + atoi(temp.substr(9,2).c_str());
        int time = end - start;

        string name = "";
        for(auto x : temp.substr(12)){
            if(x != ',')
                name += x;
            else
                break;
        }

        string music = temp.substr(13 + name.size());
        int front = 0;

        for(int i=0; i<music.size(); i++){
            if(music[i] != '#')
                front++;

            if(music[i] == m[0]){
                int length = 0;
                bool pass = true;

                for(int j=0; j<m.size(); j++){
                    if(m[j] != music[(i+j)%music.size()]){
                        pass = false;
                        break;
                    }
                    if(m[j] != '#')
                        length++;
                }

                if(pass && music[(i+m.size())%music.size()] != '#' && front -1 + length <= time){
                    songs.push_back(make_pair(make_pair(-time, n), name));
                    break;
                }
            }
        }
    }
    if(songs.size() == 0)
        return "(None)";

    sort(songs.begin(), songs.end());

    return songs.front().second;
}
