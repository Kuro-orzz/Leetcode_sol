class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> mp(wordDict.begin(), wordDict.end());
        vector<int> vis(s.size()+1, 0);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int u = q.front(); q.pop();
            string t = "";
            for(int i = u+1; i <= s.size(); i++){
                t += s[i-1];
                if(!vis[i] && mp.count(t)){
                    if(i == s.size())
                        return true;
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        return false;
    } 
};