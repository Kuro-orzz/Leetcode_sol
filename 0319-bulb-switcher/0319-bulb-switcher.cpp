class Solution {
public:
    int bulbSwitch(int n) {
        if(n < 2) return n;
        int cnt = 0;
        while(cnt*cnt <= n)
            cnt++;
        return cnt-1;
    }
};