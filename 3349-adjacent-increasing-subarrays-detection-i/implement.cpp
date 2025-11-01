class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (k == 1) return true;
        int n = nums.size();
        vector<int> v(n);
        int l = 0;
        for (int r = 1; r < n; r++) {
            if (nums[r] <= nums[r-1]) l = r;
            if (r - l + 1 >= k) v[l] = 1, l++;
        }
        for (int i = 0; i < n - k; i++) {
            if (v[i] & v[i+k]) return true;
        }
        return false;
    }
};