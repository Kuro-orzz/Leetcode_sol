class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0] = INT_MAX;
        ans[1] = -1;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == target){
                ans[0] = min(ans[0], i);
                ans[1] = max(ans[1], i);
            }
        if(ans[0] == INT_MAX)
            ans[0] = -1;
        return ans;
    }
};