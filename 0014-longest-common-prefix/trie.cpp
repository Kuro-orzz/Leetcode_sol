class Solution {
public:
    int child[201][26];
    int add(string &s){
        int u = 0;
        for(int i = 0; i < s.size(); i++){
            int k = s[i]-'a';
            if(!child[u][k])
                return i;
            u = child[u][k];
        }
        return s.size();
    }
    string longestCommonPrefix(vector<string>& strs) {
        int cnt = 0;
        int u = 0;
        for(int i = 0; i < strs[0].size(); i++){
            int k = strs[0][i]-'a';
            if(!child[u][k])
                child[u][k] = ++cnt;
            u = child[u][k];
        }
        int ans = INT_MAX;
        for(int i = 1; i < strs.size(); i++)
            ans = min(ans, add(strs[i]));     
        return strs[0].substr(0, ans);
    }
};