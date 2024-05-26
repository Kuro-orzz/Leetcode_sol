class Solution {
public:
    string compressedString(string word) {
        int cnt = 1;
        string ans = "";
        for(int i = 1; i < word.size(); i++){
            if(word[i] == word[i-1] && cnt < 9)
                cnt++;
            else{
                ans += to_string(cnt) + word[i-1];
                cnt = 1;
            }
        }
        ans += to_string(cnt) + word[word.size()-1];
        return ans;
    }
};