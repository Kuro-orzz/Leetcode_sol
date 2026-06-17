class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, base = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            base += i * nums[i];
        }
        int ans = base;
        for (int i = 1; i <= n; i++) {
            base = base + sum - n * nums[n-i];
            ans = max(ans, base);
        }
        return ans;
    }
};