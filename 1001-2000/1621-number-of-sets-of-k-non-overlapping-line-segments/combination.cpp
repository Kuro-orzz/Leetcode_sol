class Solution {
public:
    // Using for n * k <= 1e7 or n,k <= 5000, O(1) per operation
    vector<vector<int>> preprocess(int n, int k, int m) {
        vector<vector<int>> C(n+1, vector<int>(k+1));
        for (int i = 0; i <= n; i++) {
            C[i][0] = 1 % m;
            for (int j = 1; j <= min(i, k); j++) {
                C[i][j] = (1ll * C[i-1][j-1] + C[i-1][j]) % m;
            }
        }
        return C;
    }

    int numberOfSets(int n, int k) {
        int mod = 1e9 + 7;
        vector<vector<int>> C = preprocess(n, n, mod);
        long long ans = 0;
        for (int i = k; i < n; i++) {
            ans = (ans + 1ll * C[i-1][k-1] * C[n-i+k-1][n-i-1]) % mod;
        }
        return ans;
    }
};