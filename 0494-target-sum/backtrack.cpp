class Solution {
public:
    int target, ans = 0;
    vector<int> nums;
    void backtracking(int pos, int sum){
        if(pos == nums.size()){
            if(sum == target) ans++;
            return;
        }
        backtracking(pos+1, sum + nums[pos]);
        backtracking(pos+1, sum - nums[pos]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;
        backtracking(0, 0);
        return ans;
    }
};