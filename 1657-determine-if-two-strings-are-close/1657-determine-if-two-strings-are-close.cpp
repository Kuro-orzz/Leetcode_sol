class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length())
            return false;
        unordered_map<char, int> mp1;
        for(int i = 0; i < word1.length(); i++)
            mp1[word1[i]]++;
        unordered_map<char, int> mp2;
        for(int i = 0; i < word2.length(); i++)
            mp2[word2[i]]++;
        if(mp1.size() != mp2.size())
            return false;
        set<char> s;
        map<int, int> mp;
        for(auto it : mp1){
            s.insert(it.first);
            mp[it.second]++;
        }
        for(auto it : mp2){
            if(s.find(it.first) == s.end() || mp[it.second] == 0)
                return false;
            mp[it.second]--;
        }
        return true;
    }
};