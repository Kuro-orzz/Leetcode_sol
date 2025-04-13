class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < (1 << n); i++){
            int tmp = 0;
            for(int j = 0; j < n; j++)
                if(1 & (i >> j))
                    tmp ^= nums[j];
            ans += tmp;
        }
        return ans;   
    }
};