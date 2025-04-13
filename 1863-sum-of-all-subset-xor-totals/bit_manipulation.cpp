class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int x : nums)
            ans |= x;
        return ans << (n-1);
    }
};