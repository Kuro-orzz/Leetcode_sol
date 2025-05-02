class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        int invalid = -1, mx = -1, mn = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK)
                invalid = i;
            if (nums[i] == minK)
                mn = i;
            if (nums[i] == maxK)
                mx = i;
            ans += max(0, min(mn, mx)-invalid);
        }
        return ans;
    }
};