            /*  I HATE THIS PROBLEM, TOOK ME OVER 2 HOUR TO DEBUG AND OPTIMIZE  */

#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<int, int> diff[3];
        map<pii, int> mp, pref_p[3];
        mp[{0, 0}] = diff[0][0] = diff[1][0] = diff[2][0] = 0;
        pref_p[0][{0, 0}] = pref_p[1][{0, 0}] = pref_p[2][{0, 0}] = 0;
        vector<int> v(3, 0);
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            v[s[i]-'a']++;
            int cnt = (v[0] ? 1 : 0) + (v[1] ? 1 : 0) + (v[2] ? 1 : 0);
            if (i && s[i] == s[i-1]) r++;
            else l = r;
            ans = max(ans, r - l + 1);
            if (cnt == 1) {
                ans = max(ans, i + 1);
            } if (cnt == 2) {
                if (v[0] && v[1]) {
                    if (diff[0].count(v[1] - v[0])) {
                        ans = max(ans, i - diff[0][v[1] - v[0]] + 1);
                    }
                } else if (v[1] && v[2]) {
                    if (diff[1].count(v[2] - v[1])) {
                        ans = max(ans, i - diff[1][v[2] - v[1]] + 1);
                    }
                } else if (v[2] && v[0]) {
                    if (diff[2].count(v[0] - v[2])) {
                        ans = max(ans, i - diff[2][v[0] - v[2]] + 1);
                    }
                }
            } else if (cnt == 3) {
                if (mp.count({v[1] - v[0], v[2] - v[1]})) {
                    ans = max(ans, i - mp[{v[1]-v[0], v[2]-v[1]}] + 1);
                }
                if (pref_p[0].count({v[2], v[1]-v[0]})) ans = max(ans, i - pref_p[0][{v[2], v[1]-v[0]}] + 1);
                if (pref_p[1].count({v[0], v[2]-v[1]})) ans = max(ans, i - pref_p[1][{v[0], v[2]-v[1]}] + 1);
                if (pref_p[2].count({v[1], v[0]-v[2]})) ans = max(ans, i - pref_p[2][{v[1], v[0]-v[2]}] + 1);
            }
            if (!diff[0].count(v[1] - v[0])) diff[0][v[1] - v[0]] = i + 1;
            if (!diff[1].count(v[2] - v[1])) diff[1][v[2] - v[1]] = i + 1;
            if (!diff[2].count(v[0] - v[2])) diff[2][v[0] - v[2]] = i + 1;
            if (!mp.count({v[1]-v[0], v[2]-v[1]})) {
                mp[{v[1]-v[0], v[2]-v[1]}] = i + 1;
            }
            if (!pref_p[0].count({v[2], v[1]-v[0]})) pref_p[0][{v[2], v[1]-v[0]}] = i + 1;
            if (!pref_p[1].count({v[0], v[2]-v[1]})) pref_p[1][{v[0], v[2]-v[1]}] = i + 1;
            if (!pref_p[2].count({v[1], v[0]-v[2]})) pref_p[2][{v[1], v[0]-v[2]}] = i + 1;
        }
        return ans;
    }
};