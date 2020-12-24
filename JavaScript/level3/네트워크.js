function solution(n, computers) {
    var answer = 0;
    let visited = Array(n).fill(false);
    
    function dfs(location){
        visited[location] = true;
        for(let i=0; i<n; i++)
            if(computers[location][i] === 1 && i !== location && visited[i] === false)
                dfs(i);
    }   
    
    for(let i=0; i<n; i++)
        if(visited[i] === false){
            dfs(i);
            answer++;
        }
    
    return answer;
}