class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return true;
        bool inc;
        if(nums[0] < nums[n-1])
            inc = true;
        else
            inc = false;
        for(int i = 1; i < n; i++){
            if(inc && nums[i-1] > nums[i])
                return false;
            if(!inc && nums[i-1] < nums[i])
                return false;
        }
        return true;
    }
};