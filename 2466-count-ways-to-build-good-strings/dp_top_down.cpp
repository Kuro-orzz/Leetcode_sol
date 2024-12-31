class Solution {
public:
    int mod = 1e9+7;
    int ans = 0;
    int low, high, zero, one;
    vector<int> dp;
    
    int calc(int i){
        if(i < 0) return 0;
        if(i == 0) return 1;
        if(dp[i] != -1) return dp[i];
        dp[i] = (calc(i-zero) + calc(i-one)) % mod;
        return dp[i];
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        this->low = low;
        this->high = high;
        this->zero = zero;
        this->one = one;
        dp.resize(high+1, -1);
        for(int i = low; i <= high; i++)
            ans = (ans + calc(i)) % mod;
        return ans;
    }
};