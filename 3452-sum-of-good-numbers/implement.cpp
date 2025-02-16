class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int a = i-k;
            int b = i+k;
            bool check = true;
            if(i-k >= 0 && nums[i] <= nums[i-k])
                check = false;
            if(i+k < nums.size() && nums[i] <= nums[i+k])
                check = false;
            if(check) ans += nums[i];
        }
        return ans;
    }
};