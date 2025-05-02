class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        int diff = s.size();
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        int ans = 0;
        while (r < n) {
            mp[nums[r++]]++;
            if (mp.size() < diff) continue;
            while (l < r && mp.size() == diff) {
                ans += n-r+1;
                if (mp[nums[l]] == 1)
                    mp.erase(nums[l++]);
                else
                    mp[nums[l++]]--;
            }
        }
        return ans;
    }
};