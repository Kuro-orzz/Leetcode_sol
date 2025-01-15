class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n = __builtin_popcount(num2);
        int ans = 0;
        while(n){
            if(num1 == 0) break;
            ans |= (1 << __lg(num1));
            num1 ^= (1 << __lg(num1));
            n--;
        }
        for(int i = 0; n; i++){
            if((1 << i) & ans) continue;
            ans |= (1 << i);
            n--;
        }
        return ans;
    }
};