class Solution {
public:
    bool isMatch(string s, string p) {
        regex r(p);
        if(regex_match(s, r)) return true;
        return false;
    }
};