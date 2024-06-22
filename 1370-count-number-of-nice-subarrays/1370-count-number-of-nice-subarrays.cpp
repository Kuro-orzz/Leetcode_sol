class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0]++;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & 1) cnt++;
            mp[cnt]++;
        }
        int ans = 0;
        for(int i = k; i <= cnt; i++)
            ans += mp[i]*mp[i-k];
        return ans;
    }
};