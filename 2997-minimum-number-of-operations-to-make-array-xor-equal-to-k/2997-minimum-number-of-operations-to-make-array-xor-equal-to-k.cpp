class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int tmp = nums[0];
        for(int i = 1; i < nums.size(); i++)
            tmp = tmp ^ nums[i];
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if((k & (1 << i)) != (tmp & (1 << i)))
                ans++;
        }
        return ans;
    }
};