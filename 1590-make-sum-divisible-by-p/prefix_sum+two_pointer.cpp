#define ll long long

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<ll> pref(n+1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + nums[i-1];
        }
        int residual = pref[n] % p;
        if (!residual) return 0;
        map<int, int> mp;
        int ans = n;
        mp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int need = (pref[i] - residual + p) % p;
            if (mp.count(need)) {
                ans = min(ans, i - mp[need]);
            }
            mp[pref[i] % p] = i;
        }
        return ans == n ? -1 : ans;
    }
};