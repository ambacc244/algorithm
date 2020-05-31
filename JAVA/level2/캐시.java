import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        ArrayList<String> list = new ArrayList<String>();

        if(cacheSize == 0)
            return cities.length*5;

        for(int i=0; i<cities.length; i++){
            if(list.contains(cities[i].toUpperCase())){
                list.remove(cities[i].toUpperCase());
                list.add(cities[i].toUpperCase());
                answer += 1;
            }
            else{
                if(list.size() >= cacheSize)
                    list.remove(0);

                list.add(cities[i].toUpperCase());
                answer += 5;
            }
        }
        return answer;
    }
}
