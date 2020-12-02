function solution(skill, skill_trees) {
    var answer = 0;
    
    for(let i=0; i<skill_trees.length; i++){  
        let order = [];
        
        for(let j=0; j<skill.length; j++)
            order.push(skill_trees[i].indexOf(skill[j]));
        
        let maxVal = -1;
        let next = true;
        
        for(let j=0; j<order.length; j++){
            if(order[j] === -1)
                next = false;
            
            if(order[j] > maxVal && next)
                maxVal = order[j];
            else if((order[j] != -1 && !next) || (order[j] <= maxVal && next))
                break;
            
            if(j === order.length-1)
                answer++;
        }
    }
    
    return answer;
}
