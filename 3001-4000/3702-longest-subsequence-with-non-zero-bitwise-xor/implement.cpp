class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int flag = 0, res = 0;
        for (int x : nums) {
            res ^= x;
            if (x) flag = 1;
        }
        if (res) return n;
        return flag ? n-1 : 0;
    }
};