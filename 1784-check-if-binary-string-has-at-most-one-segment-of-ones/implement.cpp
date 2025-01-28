class Solution {
public:
    bool checkOnesSegment(string s) {
        bool t = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                if(t == true) return false;
                while(i < s.size() && s[i] == '1')
                    i++;
                t = true;
            }
        }
        return t;
    }
};