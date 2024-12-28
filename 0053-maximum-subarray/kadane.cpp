class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
    }
};