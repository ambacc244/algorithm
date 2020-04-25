#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int numbers = nums.size();
    map<int, int> pocket;

    while(!nums.empty()){
        map<int,int>::iterator it = pocket.find(nums.back());

        if(it == pocket.end())
            pocket.insert(make_pair(nums.back(), 1));
        else
            pocket[nums.back()]++;
        nums.pop_back();
    }

    if(pocket.size() > numbers/2)
        return numbers/2;

	return pocket.size();
}
