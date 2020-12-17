function solution(str1, str2) {
    var answer = 0;
    let arr1 = [];
    let arr2 = [];
    let index1 = 0;
    let index2 = 0;
    
    str1 = str1.toUpperCase();
    str2 = str2.toUpperCase();

    for(let i=1; i<str1.length; i++)
        if(str1[i-1] >= "A" && str1[i-1] <= "Z" && str1[i] >= "A" && str1[i] <= "Z")
            arr1.push(str1.substring(i-1, i+1));
    
    for(let i=1; i<str2.length; i++)
        if(str2[i-1] >= "A" && str2[i-1] <= "Z" && str2[i] >= "A" && str2[i] <= "Z")
            arr2.push(str2.substring(i-1, i+1));
    
    arr1.sort();
    arr2.sort();

    while(index1 < arr1.length && index2 < arr2.length){
        if(arr1[index1] === arr2[index2]){
            index1++;
            index2++;
            answer++;
        }
        else if(arr1[index1] < arr2[index2])
            index1++;      
        else
            index2++;       
    }

    if(arr1.length === 0 && arr2.length === 0)
        return 65536;
    
    return Math.floor(answer/(arr1.length + arr2.length - answer)*65536);
}