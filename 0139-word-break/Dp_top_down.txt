class Solution {
public:
    vector<int> memo;
    string s;
    vector<string> wordDict;

    bool dp(int i){
        if(i < 0)
            return true;
        if(memo[i] != -1)
            return memo[i] == 1;
        for(string word : wordDict){
            if(i-(int)word.size()+1 < 0)
                continue;
            if(s.substr(i-word.size()+1, word.size()) == word
                && dp(i-word.size())){
                memo[i] = 1;
                return true;
            }
        }
        memo[i] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memo.resize(s.size(), -1);
        this->s = s;
        this->wordDict = wordDict;
        return dp(s.size()-1);
    } 
};