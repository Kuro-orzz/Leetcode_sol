#define ll long long

class Solution {
public:
    ll GCD(ll a, ll b) { return (!b ? a : GCD(b, a % b)); }
    ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }

    bool check (long long res, vector<int> &d, vector<int> &r) {
        ll t0 = res - res / r[0];
        ll t1 = res - res / r[1];
        ll ex_in = res - res/r[0] - res/r[1] + res/LCM(r[0], r[1]);
        ll ok1 = t0 - ex_in;
        ll ok2 = t1 - ex_in;
        if (ok1 + ok2 + ex_in < d[0] + d[1]) return false;
        if (ok1 + ex_in < d[0] || ok2 + ex_in < d[1]) return false;
        return true;
    }
    
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long le = d[0] + d[1], ri = 1ll*1e18;
        long long ans = 0;
        while (le <= ri) {
            long long mid = (le + ri) / 2;
            if (check(mid, d, r)) {
                ans = mid;
                ri = mid - 1;
            } else le = mid + 1;
        }
        return ans;
    }
};