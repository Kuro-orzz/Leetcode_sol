class Solution {
private:
public:
    int ans = 0;
    void solve(int k, vector<string> &words, vector<int> &score, vector<int> &v, vector<int> &used){
        for(int x : v)
            if(x < 0)
                return;
        int tmp = 0;
        for(int i = 0; i < used.size(); i++)
            tmp += score[i] * used[i];
        ans = max(tmp, ans);
        for(int i = k; i < words.size(); i++){
            for(int x : v)
                if(x < 0)
                    return;
            tmp = 0;
            for(int i = 0; i < used.size(); i++)
                tmp += score[i] * used[i];
            ans = max(tmp, ans);
            for(int j = 0; j < words[i].size(); j++){
                v[words[i][j]-'a']--;
                used[words[i][j]-'a']++;
            }
            solve(i+1, words, score, v, used);
            for(int j = 0; j < words[i].size(); j++){
                v[words[i][j]-'a']++;
                used[words[i][j]-'a']--;
            }
        }
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> v(26, 0);
        vector<int> used(26, 0);
        for(char c : letters)
            v[c-'a']++;
        solve(0, words, score, v, used);
        return ans;
    }
};