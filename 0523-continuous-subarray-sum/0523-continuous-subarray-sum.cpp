class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        vector<long long> t;
        map<int, int> mp;
        mp[0]++;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            t.push_back(sum);
            if(i-1 >= 0 && nums[i] == 0 && nums[i-1] == 0)
                return true;
            if(mp[sum % k] > 1 || (mp[sum%k] > 0 && (sum-nums[i])%k != sum % k))
                return true;
            mp[sum % k]++;
        }
        return false;
    }
};