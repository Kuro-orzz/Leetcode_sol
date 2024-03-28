class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        while(r < nums.size()){
            if(mp[nums[r]] < k){
                mp[nums[r]]++;
                r++;
            }
            else{
                mp[nums[l]]--;
                l++;
            }
            ans = max(ans, r-l);
        }
        return ans;
    }
};