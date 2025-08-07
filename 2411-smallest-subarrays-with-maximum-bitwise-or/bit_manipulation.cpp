class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> bit(32);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                if (nums[i] >> j & 1) bit[j].push_back(i);
            }
        }
        vector<int> ans(n);
        for (int i = n-1; i >= 0; i--) {
            int t = 1;
            for (int j = 0; j < 32; j++) {
                if (nums[i] >> j & 1) continue;
                if (!bit[j].size() || bit[j].back() <= i) continue;
                int near;
                while (bit[j].size() && bit[j].back() > i) {
                    near = bit[j].back();
                    bit[j].pop_back();
                }
                t = max(t, near - i + 1);
                bit[j].push_back(near);
            }
            ans[i] = t;
        }
        return ans;
    }
};