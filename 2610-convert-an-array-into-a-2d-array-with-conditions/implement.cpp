class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> mp;
        int mx = 0;
        for (int x : nums) {
            mp[x]++;
            mx = max(mx, mp[x]);
        }
        vector<vector<int>> ans(mx);
        for (auto [val, fre] : mp) {
            for (int i = 0; i < fre; i++) {
                ans[i].push_back(val);
            }
        }
        return ans;
    }
};