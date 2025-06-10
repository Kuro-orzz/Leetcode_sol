#define ll long long
class Solution {
public:
    int count(int n, ll pref1, ll pref2) {
        int cnt = 0;
        while (pref1 <= n) {
            cnt += min(1ll*n+1, pref2) - pref1;
            pref1 *= 10;
            pref2 *= 10;
        }
        return cnt;
    }

    int findKthNumber(int n, int k) {
        ll cur = 1;
        k--;
        while (k) {
            int t = count(n, cur, cur + 1);
            if (t <= k) {
                cur++;
                k -= t;
            } else {
                cur *= 10;
                k--;
            }
        }
        return cur;
    }
};