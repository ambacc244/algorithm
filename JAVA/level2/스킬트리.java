//pair
import java.util.*;
import java.io.*;

class Pair<L,R> {
    private L key;
    private R value;

    public Pair(L key, R value) {
        this.key = key;
        this.value = value;
    }

    public L getKey(){
        return key;
    }

    public R getValue(){
        return value;
    }

    public void setKey(L key){
        this.key = key;
    }

    public void setValue(R value){
        this.value = value;
    }
}

class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        List<Pair<Character, Integer>> pairs =  new ArrayList<>();

        for(int i=0; i<skill.length(); i++)
            pairs.add(new Pair<>(skill.charAt(i), -1));

        for(int i=0; i<skill_trees.length; i++){
            for(int j=0; j<pairs.size(); j++){
                int index = skill_trees[i].indexOf(pairs.get(j).getKey());
                pairs.get(j).setValue(index);
            }

            int index = 0;

            for(int j=pairs.size()-1; j>=0; j--){
                if(pairs.get(j).getValue() != -1){
                    index = j;
                    break;
                }
            }

            if(index == 0)
                answer++;

            for(int j=1; j<=index; j++){
                if(pairs.get(j-1).getValue() >= pairs.get(j).getValue())
                    break;
                if(pairs.get(j-1).getValue() == -1)
                    break;
                if(j == index)
                    answer++;
            }
        }
        return answer;
    }
}
