class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        for (auto &it : queries) {
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int v = it[3];
            while (l <= r) {
                nums[l] = 1ll * nums[l] * v % mod;
                l += k;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};