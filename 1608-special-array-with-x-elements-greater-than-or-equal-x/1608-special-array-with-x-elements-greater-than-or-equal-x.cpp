class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(-1);
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < n; i++){
            if(nums[i] != nums[i+1] && nums[i+1] < i+1 && nums[i] >= i+1)
                return i+1;
        }
        return -1;
    }
};