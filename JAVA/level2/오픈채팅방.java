import java.util.*;

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

    public String[] solution(String[] record) {
        String[] answer = {};
        HashMap<String, String> map = new HashMap<String, String>();
        ArrayList<Pair<Character, String>> list =  new ArrayList<Pair<Character, String>>();

        for(int i=0; i<record.length; i++){
            String[] split = record[i].split("\\s+");
            String id = split[1];

            if(split[0].equals("Enter") || split[0].equals("Change")){
                String name = split[2];
                map.put(id, name);

                if(split[0].equals("Enter"))
                    list.add(new Pair<>('E', id));
            }
            else if(split[0].equals("Leave"))
                list.add(new Pair<>('L', id));
        }

        answer = new String[list.size()];

        for(int i=0; i<list.size(); i++){
            String str = map.get(list.get(i).getValue());

            if(list.get(i).getKey() == 'E')
                str += "님이 들어왔습니다.";
            else if(list.get(i).getKey() == 'L')
                str += "님이 나갔습니다.";

            answer[i] = str;
        }
        return answer;
    }
}
