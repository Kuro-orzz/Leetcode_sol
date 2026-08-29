#define ll long long

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    ll cur_sum = 1ll * nums[i] + nums[j] + nums[k];
                    auto it = equal_range(nums.begin()+k+1, nums.end(), target - cur_sum);
                    if (it.second - it.first == 0) continue;
                    s.insert({nums[i], nums[j], nums[k], *it.first});
                }
            }
        }
        vector<vector<int>> ans;
        for (auto &it : s) {
            ans.push_back(it);
        }
        return ans;
    }
};