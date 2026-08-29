class Solution {
public:
    int mod = 1e9 + 7;

    int numberOfWays(string corridor) {
        int n = corridor.size();
        int ans = 1, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (cnt && cnt % 2 == 0) {
                int p = 0;
                while (i < n && corridor[i] == 'P') p++, i++;
                if (i == n) continue;
                ans = (1ll * ans * (p+1)) % mod;
            }
            if (corridor[i] == 'S') cnt++;
        }
        return cnt < 2 || cnt % 2 ? 0 : ans;
    }
};