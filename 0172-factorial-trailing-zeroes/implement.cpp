class Solution {
public:
    int trailingZeroes(int n) {
        int tmp = 5;
        int ans = 0;
        while(tmp <= n){
            ans += n/tmp;
            tmp *= 5;
        }
        return ans;
    }
};