class Solution {
public:
    bool p[(int)5e6+1];
    void prime(int n){
        memset(p, true, sizeof(p));
        p[0] = p[1] = 0;
        for(int i = 2; i*i <= n; i++)
            if(p[i]){
                for(int j = i*i; j <= n; j+=i)
                    p[j] = 0;
            }
    }
    int countPrimes(int n) {
        prime(n);
        int ans = 0;
        for(int i = 2; i < n; i++)
            if(p[i])
                ans++;
        return ans;
    }
};