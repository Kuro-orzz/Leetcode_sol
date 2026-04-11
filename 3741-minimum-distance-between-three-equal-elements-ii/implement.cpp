class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> cnt(1e5 + 6);
        for (int i = 0; i < n; i++) {
            cnt[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            for (int j = 2; j < cnt[i].size(); j++) {
                ans = min(ans, 2 * (cnt[i][j] - cnt[i][j-2]));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};