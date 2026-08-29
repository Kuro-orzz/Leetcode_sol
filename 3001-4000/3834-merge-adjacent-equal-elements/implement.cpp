class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        long long keep = nums[0];
        vector<long long> ans;
        for (int i = 1; i < n; i++) {
            if (keep == nums[i]) {
                keep += nums[i];        
            } else {
                ans.push_back(keep);
                keep = nums[i];
            }
            while (!ans.empty() && keep == ans.back()) {
                keep += ans.back();
                ans.pop_back();
            }
        }
        ans.push_back(keep);
        return ans;
    }
};