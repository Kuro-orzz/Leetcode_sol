class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int base = 331;
        int mod = 1e9;
        int n = words.size();
        vector<long long> p(1006);
        p[0] = 1;
        for(int i = 1; i < 1006; i++)
            p[i] = p[i-1]*base%mod;
        vector<vector<long long>> H(n);
        vector<unordered_map<int, int>> mp(1006);
        for(int i = 0; i < n; i++){
            H[i].push_back(0);
            for(int j = 1; j <= words[i].size(); j++){
                H[i].push_back((H[i][j-1]*base+words[i][j-1]-'a'+1)%mod);
                mp[j-1][H[i][j]]++;
            }
        }
        auto getHash = [&](int i, int l, int r){
            return (H[i][r]-H[i][l-1]*p[r-l+1]+1ll*mod*mod)%mod;
        };
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < words[i].size(); j++){
                cnt += mp[j][getHash(i, 1, j+1)];
            }
            ans[i] = cnt;
        }
        return ans;
    }
};