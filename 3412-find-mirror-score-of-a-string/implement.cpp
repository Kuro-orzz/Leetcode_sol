// a z
// b y
// c x
// d w
// e v
// f u
// g t
// h s
// i r
// j q
// k p
// l o
// m n

class Solution {
public:
    long long calculateScore(string s) {
        vector<int> vis(s.size(), 0);
        long long ans = 0;
        vector<vector<int>> v(26);
        for(int i = 0; i < s.size(); i++){
            if(s[i]-'a' <= 12){
                if(v[s[i]-'a'].size() > 0 && s[v[s[i]-'a'].back()]-'a' > 12){
                    ans += i-v[s[i]-'a'].back();
                    v[s[i]-'a'].pop_back();
                    continue;
                }
                v[s[i]-'a'].push_back(i);
            }
            else{
                if(v['z'-s[i]].size() > 0 && s[v['z'-s[i]].back()]-'a' <= 12){
                    ans += i-v['z'-s[i]].back();
                    v['z'-s[i]].pop_back();
                    continue;
                }
                v['z'-s[i]].push_back(i);
            }
        }
        return ans;
    }
};