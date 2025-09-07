#define ll long long
#define fi first
#define se second

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        map<ll, int> mp;
        int t = 1, cnt = 1;
        mp[1] = 1;
        for (int i = 0; t < 1e9; i++) {
            t *= 4;
            mp[t] = ++cnt;
        }
        ll ans = 0;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            ll res = 0;
            auto startPos = mp.lower_bound(l);
            auto endPos = mp.upper_bound(r);
            for (auto it = startPos; it->fi < endPos->fi; it++) {
                res += it->se * (it->fi * 4 - it->fi);
            }
            if (startPos->fi != l) {
                res += (startPos->se-1) * (startPos->fi - l);
            }
            if (endPos->fi != r) {
                res -= (endPos->se-1) * (endPos->fi - r - 1);
            }
            ans += (res + 1) / 2;
        }
        return ans;
    }
};