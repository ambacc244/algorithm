function solution(n, edge) {
    let graph = Array(n).fill(null).map(()=>Array());
    let visited = Array(n).fill(-1);
    let queue = [0];
    
    visited[0] = 0;

    for(let i of edge){
        graph[i[0]-1].push(i[1]-1);
        graph[i[1]-1].push(i[0]-1);
    }

    while(visited.includes(-1) && queue.length>0){
        let val = queue.shift();
        for(let i=0; i<n; i++){
            if(visited[i] === -1 && graph[val].includes(i)){
                visited[i] = visited[val] + 1;
                queue.push(i);
            }
        }
    }
  
    let val = Math.max(...visited);
    return visited.filter((e) =>  val === e).length;
}