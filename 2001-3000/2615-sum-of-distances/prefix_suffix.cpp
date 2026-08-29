class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<long long> ans(n);
        for (auto &it : mp) {
            int sz = it.second.size();
            vector<long long> pref(sz+1, 0), suff(sz+2, 0);
            for (int i = 1; i < sz; i++) {
                pref[i+1] = pref[i] + abs(it.second[i-1] - it.second[i]) * i;
            }
            for (int i = sz-2; i>= 0; i--) {
                suff[i+1] = suff[i+2] + abs(it.second[i+1] - it.second[i]) * (sz - i - 1);
            }
            for (int i = 0; i < sz; i++) {
                ans[it.second[i]] = pref[i+1] + suff[i+1];
            }
        }
        return ans;
    }
};