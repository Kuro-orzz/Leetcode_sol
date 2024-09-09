class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i = 0; i < k; i++){
            pair<int, int> mn = {nums[0], 0};
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] < mn.first)
                    mn = {nums[j], j};
            }
            nums[mn.second] = mn.first*multiplier;
        }
        return nums;
    }
};