class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n, 0);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++)
            pre[i] = pre[i-1]+nums[i];
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        for(int i = 0; i < n; i++){
            ans += mp[pre[i]-k];
            mp[pre[i]]++;
        }
        return ans;
    }
};