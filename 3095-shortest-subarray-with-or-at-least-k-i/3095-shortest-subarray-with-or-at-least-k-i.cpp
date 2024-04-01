class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = 1000;
        for(int i = 0; i < nums.size(); i++){
            int j = i+1;
            int tmp = nums[i];
            while(j < nums.size() && tmp < k){
                tmp = tmp | nums[j];
                j++;
            }
            if(tmp >= k)
                ans = min(ans, j-i);
        }
        if(ans == 1000)
            return -1;
        return ans;
    }
};