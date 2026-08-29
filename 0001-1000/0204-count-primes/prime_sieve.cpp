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

    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<int> prime = sieve(n-1);
        int ans = 0;
        for (int x : prime) {
            if (x) ans++;
        }
        return ans;
    }
};