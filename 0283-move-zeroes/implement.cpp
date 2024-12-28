class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0;
        vector<int> tmp(nums.size());
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]){
                tmp[cnt] = nums[i];
                cnt++;
            }
            else
                zero++;
        }
        nums = tmp;
    }
};