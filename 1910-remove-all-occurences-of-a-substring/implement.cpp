class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true){
            int idx = s.find(part);
            if(idx == -1) break;
            s = s.substr(0, idx) + s.substr(idx+part.size());
        }
        return s;
    }
};