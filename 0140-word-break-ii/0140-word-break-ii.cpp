class Solution {
public:
    vector<string> ans;
    string x = "";

    void dfs(int i, int n, vector<pair<pair<int, int>, int>> &v, vector<string> &wordDict){
        if(v[i].first.second == n){
            ans.push_back(x+wordDict[v[i].second]);
            return;
        }
        x += wordDict[v[i].second]+" ";
        for(int j = i+1; j < v.size(); j++){
            if(v[j].first.first == v[i].first.second+1)
                dfs(j, n, v, wordDict);
        }
        x = x.substr(0, x.size()-wordDict[v[i].second].size()-1);
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int base = 31;
        long long mod = (long long)1e9;
        s = " " + s;
        int n = s.size();
        int m = wordDict.size();
        auto getHash = [&](int l, int r, vector<long long> &hash, vector<long long> &power){
            return (hash[r]-hash[l-1]*power[r-l+1]+mod*mod)%mod;
        };
        vector<long long> power(26);
        power[0] = 1;
        for(int i = 1; i < 26; i++)
            power[i] = (power[i-1] * base) % mod;
        vector<long long> hashS(n);
        hashS[0] = 0;
        for(int i = 1; i < n; i++)
            hashS[i] = (hashS[i-1]*base + s[i]-'a'+1) % mod;
        vector<long long> word(m, 0);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < wordDict[i].size(); j++)
                word[i] = (word[i]*base + wordDict[i][j]-'a'+1) % mod;
        vector<pair<pair<int, int>, int>> v;
        for(int i = 0; i < m; i++){
            if(wordDict[i].size() <= s.size()-1){
                for(int j = 1; j <= n-wordDict[i].size(); j++){
                    if(word[i] == getHash(j, j+wordDict[i].size()-1, hashS, power))
                        v.push_back({{j, j+wordDict[i].size()-1}, i});
                }
            }
        }
        auto cmp = [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
            if(a.first.first != b.first.first)
                return a.first.first < b.first.first;
            else
                return a.first.second < b.first.second;
        };
        sort(v.begin(), v.end(), cmp);
        for(int i = 0; i < v.size(); i++)
            if(v[i].first.first == 1)
                dfs(i, n-1, v, wordDict);
        return ans;
    }
};