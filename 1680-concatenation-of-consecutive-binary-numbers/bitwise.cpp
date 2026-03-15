class Solution {
public:
    int mod = 1e9 + 7;

    int concatenatedBinary(int n) {
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = (ans * (1 << (__lg(i) + 1)) + i) % mod;
        }
        return ans;
    }
};