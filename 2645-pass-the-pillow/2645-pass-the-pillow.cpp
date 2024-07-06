class Solution {
public:
    int passThePillow(int n, int time) {
        int t = 2*(n-1);
        time %= t;
        if(time < n)
            return time+1;
        else{
            time -= n-1;
            return n-time;
        }
    }
};