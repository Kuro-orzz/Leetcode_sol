class Solution {
public:
    bool isMatch(string s, string p) {
        regex r(p);
        auto it = sregex_iterator(s.begin(), s.end(), r);
        smatch match = *it;
        if(match.size() == 0) return false;
        string x = match[0];
        return x.size() == s.size();
    }
};