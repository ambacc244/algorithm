import java.util.*;

PriorityQueue<Integer> min = new PriorityQueue<Integer>(Collections.reverseOrder());
PriorityQueue<Integer> max = new PriorityQueue<Integer>();

min.add(1);  //1을 PriorityQueue에 넣음
min.poll();  //가장 작은 수를 빼고 return
min.peek();  //가장 작은 수를 return
