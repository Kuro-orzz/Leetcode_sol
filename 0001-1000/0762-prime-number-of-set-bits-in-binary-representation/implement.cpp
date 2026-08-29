class Solution {
public:
    vector<int> sieve(int n) {
        vector<int> nt(n+1, 1);
        nt[0] = nt[1] = 0;
        for (int i = 2; i * i <= n; i++) {
            if (!nt[i]) continue;
            for (int j = i * i; j <= n; j += i)
                nt[j] = 0;
        }
        return nt;
    }

    int countPrimeSetBits(int left, int right) {
        vector<int> nt = sieve(32);
        int ans = 0;
        for (int i = left; i <= right; i++) {
            if (nt[__builtin_popcount(i)]) ans++;
        }
        return ans;
    }
};