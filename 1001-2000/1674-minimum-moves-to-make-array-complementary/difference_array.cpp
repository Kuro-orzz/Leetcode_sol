class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2*limit+2, 0);
        for (int i = 0; i < n/2; i++) {
            int mn = min(nums[i], nums[n-i-1]);
            int mx = max(nums[i], nums[n-i-1]);
            int sum = nums[i] + nums[n-i-1];
            // 1 move
            diff[mn+1]++; diff[sum]--;
            diff[sum+1]++; diff[mx+limit+1]--;
            // 2 move
            diff[2] += 2; diff[mn+1] -= 2;
            diff[limit+mx+1] += 2; diff[2*limit+1] -= 2;
        }
        int ans = INT_MAX;
        for (int i = 2; i <= 2*limit; i++) {
            diff[i] += diff[i-1];
            ans = min(ans, diff[i]);
        }
        return ans;
    }
};