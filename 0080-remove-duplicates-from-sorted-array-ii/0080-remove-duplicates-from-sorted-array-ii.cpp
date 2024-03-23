class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mp;
        for(int x : nums)
            mp[x]++;
        int ans = 0;
        int i = 0;
        for(auto it : mp){
            if(it.second > 2){
                ans += it.second-2;
                it.second = 2;
            }
            while(it.second--){
                nums[i] = it.first;
                i++;
            }
        }
        return nums.size()-ans;
    }
};