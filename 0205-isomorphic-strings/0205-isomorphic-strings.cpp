class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> v1;
        string k = "";
        for(int i = 0; i < t.size(); i++){
            if(v1[t[i]] == 0)
                v1[t[i]] = i+1;
            k += v1[t[i]] + '0';            
        }
        unordered_map<char, int> v2;
        string tmp = "";
        for(int i = 0; i < s.size(); i++){
            if(v2[s[i]] == 0)
                v2[s[i]] = i+1;
            tmp += v2[s[i]] + '0';
        }
        if(tmp == k)
            return true;
        return false;
    }
};