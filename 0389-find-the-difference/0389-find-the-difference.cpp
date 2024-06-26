class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        for(int i = 0; i < t.size(); i++){
            if(mp[t[i]])
                mp[t[i]]--;
            else
                return t[i];
        }
        return '0';
    }
};