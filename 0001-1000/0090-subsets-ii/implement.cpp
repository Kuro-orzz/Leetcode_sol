class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for (int i = 0; i < (1 << n); i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) v.push_back(nums[j]);
            }
            s.insert(v);
        }
        vector<vector<int>> ans;
        for (auto &it : s) ans.push_back(it);
        return ans;
    }
};