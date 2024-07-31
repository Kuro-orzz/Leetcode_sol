class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int l = 0, r = nums.size()-4;
        while(l < 4){
            ans = min(ans, nums[r]-nums[l]);
            l++, r++;
        }
        return ans;
    }
};