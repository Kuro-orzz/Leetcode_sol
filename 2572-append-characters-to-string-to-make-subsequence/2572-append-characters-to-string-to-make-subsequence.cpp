class Solution {
public:
    int appendCharacters(string s, string t) {
        int p1, p2;
        p1 = p2 = 0;
        while(p1 < s.size() && p2 < t.size()){
            if(s[p1] == t[p2])
                p2++;
            p1++;
        }
        return t.size() - p2;
    }
};