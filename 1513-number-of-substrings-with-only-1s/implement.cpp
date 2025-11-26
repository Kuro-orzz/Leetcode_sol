class Solution {
public:
    int numSub(string s) {
        int mod = 1e9 + 7;
        int cnt = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') cnt++;
            else {
                ans = (ans + 1ll * cnt * (1 + cnt) / 2) % mod;
                cnt = 0;
            }
        }
        ans = (ans + 1ll * cnt * (1 + cnt) / 2) % mod;
        return ans;
    }
};