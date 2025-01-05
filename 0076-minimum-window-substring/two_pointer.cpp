#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> v_t(60, 0);
        for(int i = 0; i < t.length(); i++)
            v_t[t[i]-'A']++;
        int num = 0;
        for(int x : v_t) if(x) num++;
        pii ans = {0, INT_MAX};
        int l = 0, r = 0;
        vector<int> v_s(60, 0);
        int cnt = 0;
        while(r < s.size()){
            v_s[s[r]-'A']++;
            if(v_t[s[r]-'A'] && v_s[s[r]-'A'] == v_t[s[r]-'A']) cnt++;
            if(cnt == num){
                while(l < r && (!v_t[s[l]-'A'] || v_s[s[l]-'A']-1 >= v_t[s[l]-'A'])){
                    if(v_t[s[l]-'A']) v_s[s[l]-'A']--;
                    l++;
                }
                if(ans.se-ans.fi > r-l) ans = {l, r};
                cnt--;
                v_s[s[l]-'A']--;
                l++;
            }
            r++;
        }
        if(ans.se == INT_MAX) return "";
        return s.substr(ans.fi, ans.se-ans.fi+1);
    }
};