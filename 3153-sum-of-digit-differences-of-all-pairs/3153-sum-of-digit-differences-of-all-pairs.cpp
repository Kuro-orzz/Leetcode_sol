class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans = 0;
        int n = to_string(nums[0]).size();
        unordered_map<int, int> mp[n];
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < n; j++){
                for(auto it : mp[j])
                    if(nums[i]%10 != it.first)
                        ans += it.second;
                mp[j][nums[i]%10]++;
                nums[i] /= 10;
            }
        }
        return ans;
    }
};