class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for(int i = 0; i < s.size(); i++){
            if(!dp[i]) continue;
            for(string word : wordDict){
                if(i+word.size() > s.size())
                    continue;
                if(s.substr(i, word.size()) == word)
                    dp[i+word.size()] = 1;
            }
        }
        return dp[s.size()];
    } 
};