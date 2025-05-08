class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;
        int ans = 0;
        for (auto &t : dominoes) {
            if (t[0] > t[1]) swap(t[0], t[1]);
            if (mp.count({t[0], t[1]}))
                ans += mp[{t[0], t[1]}];
            mp[{t[0], t[1]}]++;
        }
        return ans;
    }
};