#define ll long long
class Solution {
public:
    int n, k, ans;

    int count(ll pref1, ll pref2) {
        int res = 0;
        while (pref1 <= n) {
            res += min(1ll * n + 1, pref2) - pref1;
            pref1 *= 10;
            pref2 *= 10;
        }
        return res;
    }

    void dfs(ll cur) {
        if (ans) return;
        for (int i = 0; i <= 9; i++) {
            if (!k) ans = cur;
            int t = count(cur, cur + 1);
            if (t <= k) {
                k -= t;
                cur++;
            } else {
                k--;
                dfs(cur * 10);
            }
        }
    }

    int findKthNumber(int n, int k) {
        this->n = n;
        this->k = k - 1;
        dfs(1);
        return ans;
    }
};