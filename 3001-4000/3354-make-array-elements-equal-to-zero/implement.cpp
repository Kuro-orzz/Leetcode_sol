class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n+1);
        pref[0] = 0;
        for (int i = 1; i <= n; i++) pref[i] = pref[i-1] + nums[i-1];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (nums[i-1]) continue;
            int t = abs(pref[i-1] - (pref[n] - pref[i]));
            if (t == 0) ans += 2;
            else if (t == 1) ans++;
        }
        return ans;
    }
};