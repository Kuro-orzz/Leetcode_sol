#define ll long long

class Solution {
public:
    ll GCD(ll a, ll b) { return (!b ? a : GCD(b, a % b)); }
    ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans = {nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            while (!ans.empty() && GCD(ans.back(), nums[i]) > 1) {
                int val = LCM(ans.back(), nums[i]);
                ans.pop_back();
                nums[i] = val;
            }
            ans.push_back(nums[i]);
        }
        return ans;
    }
};