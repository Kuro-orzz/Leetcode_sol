class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 1;
        if(nums.size() == 1)
            return nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1])
                cnt++;
            else
                cnt = 1;
            if(cnt > nums.size()/2)
                return nums[i];
        }
        return 0;
    }
};