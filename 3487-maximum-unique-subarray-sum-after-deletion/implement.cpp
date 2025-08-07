class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = 0, mx = -1e9;
        vector<int> cnt(106);
        for (int &x : nums) {
            if (x > 0 && !cnt[x]) {
                cnt[x]++;
                ans += x;
            }
            mx = max(mx, x);
        }   
        if (ans) return ans;
        return mx;
    }
};