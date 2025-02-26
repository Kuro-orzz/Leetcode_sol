class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx = INT_MIN, mn = INT_MAX;
        int sum1 = 0, sum2 = 0;
        for(int x : nums){
            sum1 = max(sum1+x, 0);
            mx = max(mx, sum1);
            sum2 = min(sum2+x, 0);
            mn = min(mn, sum2);
        }
        return max(abs(mx), abs(mn));
    }
};