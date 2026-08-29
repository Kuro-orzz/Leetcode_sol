#define ll long long

class Solution {
public:
    int mountain_reduce(ll time, int workTime) {
        ll k = time / workTime;
        int l = 0, r = 1e9;
        int res = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (1ll * mid * (1 + mid) / 2 <= k) {
                l = mid + 1;
                res = mid;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();
        ll ans = 0, l = 0, r = 1e18;
        while (l <= r) {
            ll mid = (l + r) >> 1ll;
            ll cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += mountain_reduce(mid, workerTimes[i]);
            }
            if (cnt >= mountainHeight) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};