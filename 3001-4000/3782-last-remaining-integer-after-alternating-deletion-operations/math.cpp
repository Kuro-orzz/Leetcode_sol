#define ll long long

class Solution {
public:
    long long lastInteger(long long n) {
        ll cur_start = 1;
        ll cur_dist = 1;
        while (n > 1) {
            // op1:
            cur_dist *= 2;
            n = (n + 1) / 2;
            // op2:
            if (n % 2 == 0) cur_start += cur_dist;
            cur_dist *= 2;
            n = (n + 1) / 2;
        }        
        return cur_start;
    }
};