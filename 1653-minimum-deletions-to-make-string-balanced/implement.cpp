class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> pref(n+1);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + (s[i-1] == 'a' ? 1 : 0);
        }
        int ans = n;
        for (int i = 0; i <= n; i++) {
            ans = min(ans, i - pref[i] + pref[n] - pref[i]);
        }
        return ans;
    }
};