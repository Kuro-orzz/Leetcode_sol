#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        vector<pii> pref(n+1, {0, 0});
        for (int i = 0; i < n; i++) {
            if (s[i] == 'U') pref[i+1] = {pref[i].fi, pref[i].se + 1};
            else if (s[i] == 'D') pref[i+1] = {pref[i].fi, pref[i].se-1};
            else if (s[i] == 'L') pref[i+1] = {pref[i].fi-1, pref[i].se};
            else if (s[i] == 'R') pref[i+1] = {pref[i].fi+1, pref[i].se};
        }
        set<pii> st;
        for (int i = k; i <= n; i++) {
            int x = pref[n].fi - pref[i].fi + pref[i-k].fi;
            int y = pref[n].se - pref[i].se + pref[i-k].se;
            st.insert({x, y});
        }
        return st.size();
    }
};