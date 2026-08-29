class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref_max(n+1, 0), suff_min(n+2, INT_MAX);
        for (int i = 1; i <= n; i++) {
            pref_max[i] = max(pref_max[i-1], nums[i-1]);
        }
        for (int i = n; i >= 1; i--) {
            suff_min[i] = min(suff_min[i+1], nums[i-1]);
        }
        for (int i = 0; i < n; i++) {
            if (pref_max[i+1] - suff_min[i+1] <= k) {
                return i;
            }
        }
        return -1;
    }
};