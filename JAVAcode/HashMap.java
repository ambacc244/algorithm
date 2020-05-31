import java.util.*;

HashMap<String, Integer> map = new HashMap<String, Integer>();

map.put("str", 1);  //key: str, val:1을 HashMap에 넣음
map.get("str");  //str을 key로 하는 val을 return
map.containsKey("str")  //str을 key로 하는 val이 존재하면 true, 아님, false
