class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n);
        set<int> dry;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (!rains[i]) {
                dry.insert(i);
            } else {
                if (mp.count(rains[i])) {
                    auto it = dry.upper_bound(mp[rains[i]]);
                    if (it == dry.end()) return {};
                    else {
                        int day = *it;
                        dry.erase(day);
                        ans[day] = rains[i];
                    }
                }
                ans[i] = -1;
                mp[rains[i]] = i;
            }
        }
        for (int x : dry) {
            ans[x] = 1;
        }
        return ans;
    }
};