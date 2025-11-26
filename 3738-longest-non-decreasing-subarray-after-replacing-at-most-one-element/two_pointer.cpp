#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<pii> v(n, {0, 0});
        int l = 0, cnt = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i-1] <= nums[i]) continue;
            for (int j = l; j < i; j++) {
                v[j] = {l, i};
            }
            l = i;
        }
        for (int j = l; j < n; j++) {
            v[j] = {l, n};
        }
        int ans = 0;
        for (pii it : v) ans = max(ans, it.se - it.fi);
        if (ans < n) ans++;
        for (int i = 1; i < n; i++) {
            if (i + 1 < n && nums[i-1] <= nums[i+1]) {
                int tmp = i - v[i-1].fi + v[i+1].se - i;
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};