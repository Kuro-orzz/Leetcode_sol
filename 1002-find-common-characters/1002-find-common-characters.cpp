class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> v(26, INT_MAX);
        for(int i = 0; i < words.size(); i++){
            vector<int> t(26, 0);
            for(char c : words[i])
                t[c-'a']++;
            for(int j = 0; j < 26; j++)
                v[j] = min(v[j], t[j]);
        }
        vector<string> ans;
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < v[i]; j++)
                ans.push_back(string(1, (char)(i+'a')));
        return ans;
    }
};