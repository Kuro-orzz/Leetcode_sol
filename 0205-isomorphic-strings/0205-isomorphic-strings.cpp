class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> v1;
        unordered_map<char, int> v2;
        for(int i = 0; i < t.size(); i++){
            if(v1[t[i]] == 0)
                v1[t[i]] = i+1;
            if(v2[s[i]] == 0)
                v2[s[i]] = i+1; 
            if(v1[t[i]] != v2[s[i]])
                return false;
        }
        return true;
    }
};