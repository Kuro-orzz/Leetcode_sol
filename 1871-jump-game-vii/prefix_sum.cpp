class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> pref(n+1, 0);
        pref[0] = 1;
        pref[1] = -1;
        for (int i = 0; i < n; i++) {
            if (i) pref[i] += pref[i-1];
            if (s[i] == '0' && pref[i]) {
                pref[min(i+minJump, n)]++;
                pref[min(i+maxJump+1, n)]--;
            }
        }
        return s[n-1] == '0' && pref[n-1];
    }
};