class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        long long base = 31;
        long long mod = 1e9+7;
        vector<long long> p(s.size()+1);
        p[0] = 1;
        for(int i = 1; i <= s.size(); i++)
            p[i] = p[i-1] * base % mod;
        vector<int> h(s.size()+1);
        h[0] = 0;
        for(int i = 1; i <= s.size(); i++)
            h[i] = (h[i-1]*base + s[i-1]-'a') % mod;
        vector<int> v_hw;
        for(int i = 0; i < words.size(); i++){
            int hw = 0;
            for(int j = 0; j < words[i].size(); j++)
                hw = (hw*base + words[i][j]-'a') % mod;
            v_hw.push_back(hw);
        }
        sort(v_hw.begin(), v_hw.end());
        auto getHash = [&](int l, int r){
            return (h[r]-1ll*h[l-1]*p[r-l+1]+mod*mod) % mod;
        };
        int len = words[0].size();
        vector<int> ans;
        for(int i = 1; i <= (int)s.size()-(int)words.size()*len+1; i++){
            vector<int> v_hs;
            for(int j = i; j < i+words.size()*len; j+=len)
                v_hs.push_back(getHash(j, j+len-1));
            sort(v_hs.begin(), v_hs.end());
            bool t = true;
            for(int i = 0; i < v_hs.size(); i++)
                if(v_hs[i] != v_hw[i]) t = false;
            if(t) ans.push_back(i-1);
        }
        return ans;
    }
};