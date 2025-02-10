class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]-i]++;
        long long ans = 0;
        for(auto it : mp)
            ans += 1ll*(it.second-1)*it.second/2;
        return 1ll*n*(n-1)/2-ans;
    }
};