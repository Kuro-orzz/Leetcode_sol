#define ll long long

class Solution {
public:
    ll GCD(ll a, ll b) { return (!b ? a : GCD(b, a % b)); }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int mx = nums[0];
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = GCD(nums[i], mx);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        ll ans = 0;
        for (int i = 0; i < n/2; i++) {
            ans += GCD(prefixGcd[i], prefixGcd[n-i-1]);
        }
        return ans;
    }
};