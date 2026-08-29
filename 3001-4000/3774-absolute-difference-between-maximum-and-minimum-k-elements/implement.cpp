class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int sumLarge = 0, sumSmall = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < k; i++) sumSmall += nums[i];
        for (int i = n-1; i >= n-k; i--) sumLarge += nums[i];
        return sumLarge - sumSmall;
    }
};