class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        // pref: 1->n
        // suf: n->1
        vector<int> pref(n+1), suf(n+2);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + (s[i-1] == '1' ? 1 : 0);
            suf[n-i+1] = suf[n-i+2] + (s[n-i] == '0' ? 1 : 0);
        }
        int ans = 1e9;
        for (int i = 0; i <= n; i++) {
            ans = min(ans, pref[i] + suf[i+1]);
        }
        return ans;
    }
};