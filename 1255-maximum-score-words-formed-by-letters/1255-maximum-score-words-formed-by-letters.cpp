class Solution {
public:
    unordered_map<char, int> mp;
    unordered_map<char, int> used;
    int ans = 0;
    void solve(int k, vector<string> &words, vector<int> &score){
        for(auto it : mp)
            if(it.second < 0)
                return;
        int tmp = 0;
        for(auto it : used)
            tmp += score[it.first-'a'] * it.second;
        ans = max(tmp, ans);
        for(int i = k; i < words.size(); i++){
            for(auto it : mp)
                if(it.second < 0)
                    return;
            tmp = 0;
            for(auto it : used)
                tmp += score[it.first-'a'] * it.second;
            ans = max(tmp, ans);
            for(int j = 0; j < words[i].size(); j++){
                mp[words[i][j]]--;
                used[words[i][j]]++;
            }
            solve(i+1, words, score);
            for(int j = 0; j < words[i].size(); j++){
                mp[words[i][j]]++;
                used[words[i][j]]--;
            }
        }
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for(char c : letters)
            mp[c]++;
        solve(0, words, score);
        return ans;
    }
};