class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n);
        int cur_last = 0;
        for (int i = 0; i < n; i++) {
            cur_last = (cur_last * 2 + nums[i]) % 10; 
            if (cur_last % 5 == 0) ans[i] = true;
            else ans[i] = false;
        }
        return ans;
    }
};