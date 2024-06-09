class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0]++;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0)
                nums[i] = k - abs(nums[i] % k);
            sum += nums[i];
            ans += mp[sum % k];
            mp[sum % k]++;
        }
        return ans;
    }
};