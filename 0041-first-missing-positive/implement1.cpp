class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool a[100002];
        memset(a, true, sizeof(a));
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0 && nums[i] <= 100000)
                a[nums[i]] = false;
        for(int i = 1; i <= 100001; i++)
            if(a[i])
                return i;
        return -1;
    }
};