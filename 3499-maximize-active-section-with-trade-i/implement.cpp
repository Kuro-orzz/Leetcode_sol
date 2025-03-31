#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s = "1" + s + "1";
        int cnt = 1;
        int cnt1 = 0;
        vector<pii> v;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '1' && i < s.size()-1)
                cnt1++;
            if(s[i] != s[i-1]){
                v.push_back({s[i-1]-'0', cnt});
                cnt = 1;
            }
            else cnt++;
        }
        v.push_back({s.back()-'0',cnt});
        int ans = cnt1;
        for(int i = 1; i < v.size()-1; i++){
            if(v[i].fi == 0) continue;
            else ans = max(ans, cnt1+v[i-1].se+v[i+1].se);
        }
        return ans;
    }
};