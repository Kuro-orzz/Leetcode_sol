class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0, cnt = 0;
        int l = 0, r = 0;
        unordered_map<int, int> mp;
        while(r < n) {
            cnt -= mp[nums[r]] * (mp[nums[r]] - 1) / 2;
            mp[nums[r]]++;
            cnt += mp[nums[r]] * (mp[nums[r]] - 1) / 2;
            if(cnt >= k) ans += n-r;
            while(l < r && cnt >= k) {
                cnt -= mp[nums[l]] * (mp[nums[l]] - 1) / 2;
                mp[nums[l]]--;
                cnt += mp[nums[l]] * (mp[nums[l]] - 1) / 2;
                if(cnt >= k) ans += n-r;
                l++;
            }
            r++;
        }    
        return ans;
    }
};