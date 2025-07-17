class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int pos = 0;
        while (pos < n) {
            auto it = upper_bound(nums.begin(), nums.end(), nums[pos]+k)-nums.begin();
            pos = it;
            ans++;
        }
        return ans;
    }
};