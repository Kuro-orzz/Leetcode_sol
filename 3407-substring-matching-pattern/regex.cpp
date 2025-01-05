class Solution {
public:
    bool hasMatch(string s, string p) {
        int p1 = 0, p2 = 0;
        int pos = p.find("*");
        auto it1 = s.find(p.substr(0, pos));
        auto it2 = s.substr(it1+pos).find(p.substr(pos+1));
        return !(it1 > s.size() || it2 > s.size());
    }
};