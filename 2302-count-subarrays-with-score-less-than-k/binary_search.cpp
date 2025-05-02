#define ll long long
class Solution {
public:
    vector<ll> pref;

    int bs(int l, int r, ll k) {
        int le = l;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if ((pref[mid]-pref[le-1])*(mid-le+1) < k) {
                ans = max(ans, mid-le+1);
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }

    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        pref.resize(n+1);
        for (int i = 0; i < nums.size(); i++) {
            pref[i+1] = pref[i] + nums[i];
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += bs(i+1, n, k);
        }
        return ans;
    }
};