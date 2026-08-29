class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int mn = 1e9, mx = -1e9;
        for (int &x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
        }
        return __gcd(mn, mx);
    }
};