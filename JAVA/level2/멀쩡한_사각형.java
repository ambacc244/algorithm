class Solution {

    public int gcd(int w, int h){
        if(w == 0 || h == 0)
            return w == 0 ? h : w;

        if(w < h){
            int temp = w;
            w = h;
            h = temp;
        }

        return gcd(h, w%h);
    }

    public long solution(int w, int h) {
        long answer = 1;
        int val = gcd(w, h);

        return (long)w*(long)h - (long)(w/val + h/val - 1)*(long)val;
    }
}
