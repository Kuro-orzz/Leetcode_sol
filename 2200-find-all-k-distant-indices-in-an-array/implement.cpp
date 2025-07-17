class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != key) continue;
            for (int j = max(idx, i-k); j <= min(n-1, i+k); j++) {
                ans.push_back(j);
            }
            idx = i+k+1;
        }
        return ans;
    }
};