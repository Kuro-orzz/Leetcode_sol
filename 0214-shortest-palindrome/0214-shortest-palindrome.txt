class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.size() <= 1)
            return s;
        int base = 97;
        int mod = 1e9;
        vector<long long> p(s.size()+1);
        p[0] = 1;
        for(int i = 1; i <= s.size(); i++)
            p[i] = p[i-1]*base%mod;
        vector<long long> H1(s.size()+2);
        H1[0] = 0;
        for(int i = 1; i <= s.size(); i++)
            H1[i] = (H1[i-1]*base+s[i-1]-'a'+1)%mod;
        vector<long long> H2(s.size()+2);
        H2[s.size()+1] = 0;
        for(int i = s.size(); i >= 1; i--)
            H2[i] = (H2[i+1]*base+s[i-1]-'a'+1)%mod;
        auto getHash1 = [&](int l, int r){
            return (H1[r]-H1[l-1]*p[r-l+1]+1ll*mod*mod)%mod;
        };
        auto getHash2 = [&](int l, int r){
            return (H2[l]-H2[r+1]*p[r-l+1]+1ll*mod*mod)%mod;
        };
        int t = 1;
        for(int i = 1; i <= s.size()/2; i++){
            if(2*i <= s.size() && getHash1(1, i) == getHash2(i+1, 2*i))
                t = max(t, 2*i);
            if(2*i+1 <= s.size() && getHash1(1, i) == getHash2(i+2, 2*i+1))
                t = max(t, 2*i+1);
        }
        string x = s.substr(max(1, t));
        reverse(x.begin(), x.end());
        return x+s;
    }
};