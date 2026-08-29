class Solution {
public:
    static bool cmp(int &a, int &b) {
        return abs(a) < abs(b);
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), cmp);
        long long ans = 0;
        for (int i = 0; i < n/2; i++) {
            ans -= 1ll * nums[i] * nums[i];
        }
        for (int i = n/2; i < n; i++) {
            ans += 1ll * nums[i] * nums[i];
        }
        return ans;
    }
};