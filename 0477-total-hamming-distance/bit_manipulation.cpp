class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> bit(32, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 32; j++)
                if(nums[i] >> j & 1)
                    bit[j]++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 32; j++)
                if(nums[i] >> j & 1)
                    ans += n-bit[j];
                else ans += bit[j];
        }
        return ans/2;
    }
};