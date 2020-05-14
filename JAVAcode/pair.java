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

class Pair<L,R> {
    L key;
    R value;

    public Pair(L key, R value) {
        this.key = key;
        this.value = value;
    }
}


/**
List<Pair<Character, Integer>> pairs =  new ArrayList<>();
pairs.add(new Pair<>(skill.charAt(i), -1));
**/
