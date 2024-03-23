class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        for(int x : nums)
            ans = min(ans, x);
        return ans;
    }
};