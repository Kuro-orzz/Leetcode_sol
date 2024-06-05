class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> v(26, INT_MAX);
        for(int i = 0; i < words.size(); i++){
            unordered_map<char, int> mp;
            for(char c : words[i])
                mp[c]++;
            for(int j = 0; j < 26; j++)
                v[j] = min(v[j], mp[char(j+'a')]);
        }
        vector<string> ans;
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < v[i]; j++)
                ans.push_back(string(1, (char)(i+'a')));
        return ans;
    }
};