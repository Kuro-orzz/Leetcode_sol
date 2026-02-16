class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int &x : nums) {
            sum += x;
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            sum -= nums[i];
            if (nums[i] > sum / (n-i-1)) ans++;
        }
        return ans;
    }
};