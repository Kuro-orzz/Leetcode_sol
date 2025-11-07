#define ll long long

class Solution {
public:
    bool check(vector<ll> &power, ll mnRes, int r, int k) {
        int n = power.size();
        vector<ll> dec(n, 0);
        ll cur_inc = 0;
        for (int i = 0; i < n; i++) {
            cur_inc -= dec[i];
            if (power[i] + cur_inc < mnRes) {
                ll numInc = mnRes - power[i] - cur_inc;
                if (numInc > k) return false;
                else k -= numInc;
                cur_inc += numInc;
                if (i+2*r+1 < n) dec[i+2*r+1] += numInc;
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<ll> pref(n+1, 0), power(n);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + stations[i-1];
        }
        for (int i = 0; i < n; i++) {
            power[i] = pref[min(i+1+r, n)] - pref[max(i-r, 0)];
        }
        ll le = 0, ri = 1e12, ans = 0;
        while (le <= ri) {
            ll mid = (le + ri) >> 1;
            if (check(power, mid, r, k)) {
                le = mid + 1;
                ans = mid;
            } else {
                ri = mid - 1;
            }
        }
        return ans;
    }
};