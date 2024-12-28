class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int multi = 1;
        int zero = 0;
        int multi2 = 1;
        for(int i = 0; i < nums.size(); i++){
            multi *= nums[i];
            if(nums[i] != 0)
                multi2 *= nums[i];
            else
                zero++;
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != 0)
                ans.push_back(multi / nums[i]);
            else if(nums[i] == 0 && zero == 1)
                ans.push_back(multi2);
            else
                ans.push_back(0);
        return ans;
    }
};