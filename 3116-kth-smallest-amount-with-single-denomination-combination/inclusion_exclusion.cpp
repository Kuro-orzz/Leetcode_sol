#define ll long long

class Solution {
public:
    ll GCD(ll a, ll b) {
        a = llabs(a), b = llabs(b);
        return (!b ? a : GCD(b, a % b));
    }
    ll LCM(ll a, ll b) { return (!a || !b) ? 0 : llabs(a / GCD(a, b) * b); }

    ll count(vector<int> &coins, ll x) {
        int n = coins.size();
        ll res = 0;
        for (int i = 1; i < (1 << n); i++) {
            ll lcm = 1;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    lcm = LCM(lcm, coins[j]);
                }
            }
            if (__builtin_parityll(i)) {
                res += x / lcm;
            } else {
                res -= x / lcm;
            }
        }
        return res;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int flag = true;
            for (int j = 0; j < n; j++) {
                if (i != j && coins[i] % coins[j] == 0) flag = false; 
            }
            if (flag) v.push_back(coins[i]);
        }
        ll le = 0, hi = 1e18, ans = 0;
        while (le <= hi) {
            ll mid = (le + hi) >> 1ll;
            ll cnt = count(v, mid);
            if (cnt < k) {
                le = mid + 1;
            } else if (cnt >= k) {
                ans = mid;
                hi = mid - 1;
            }
        }
        return ans;
    }
};