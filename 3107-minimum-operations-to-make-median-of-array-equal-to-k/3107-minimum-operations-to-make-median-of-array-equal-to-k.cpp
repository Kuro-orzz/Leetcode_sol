class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int pos = nums.size()/2;
        if(nums[pos] > k){
            while(pos >= 0 && nums[pos] > k){
                ans += abs(nums[pos]-k);
                pos--;   
            }
        }
        else if(nums[pos] < k){
            while(pos < nums.size() && nums[pos] < k){
                ans += abs(nums[pos]-k);
                pos++;
            }
        }
        return ans;
    }
};