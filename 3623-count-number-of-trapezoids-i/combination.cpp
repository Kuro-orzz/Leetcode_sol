#define fi first
#define se second
#define ll long long

class Solution {
public:
    int mod = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        map<int, int> mp;
        for (auto &it : points) {
            mp[it[1]]++;
        }
        vector<ll> v;
        ll cnt_segment = 0;
        for (auto &it : mp) {
            if (it.se == 1) continue;
            ll cnt = 1ll * it.se * (it.se - 1) / 2;
            cnt_segment += cnt;
            v.push_back(cnt);
        }
        ll ans = 0;
        for (auto &x : v) {
            ans = (ans + x * (cnt_segment - x)) % mod;
            cnt_segment -= x;
        }
        return ans;
    }
};