class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(1e5+6, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int even = 0, odd = 0;
            for (int j = i; j < n; j++) {
                even += (!memo[nums[j]] && !(nums[j] & 1) ? 1 : 0);
                odd += (!memo[nums[j]] && (nums[j] & 1) ? 1 : 0);
                memo[nums[j]]++;
                if (even == odd) ans = max(ans, j - i + 1);
            }
            for (int j = i; j < n; j++) memo[nums[j]] = 0;
        }
        return ans;
    }
};