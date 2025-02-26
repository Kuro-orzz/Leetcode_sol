class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2){
            string x = "";
            for(int i = 0; i < s.size()-1; i++)
                x += (s[i]+s[i+1]-2*'0')%10+'0';
            s = x;
        }
        return s[0] == s[1];
    }
};