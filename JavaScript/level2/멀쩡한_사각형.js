function gcd(a, b){
    if(a === 0)
        return b;
    return gcd(b%a, a);
}

function solution(w, h) {
    var answer = 1;
    let val;
    
    if(w > h)
        val = gcd(h, w);
    else
        val = gcd(w, h);

    return w*h - (w/val + h/val - 1)*val;
}