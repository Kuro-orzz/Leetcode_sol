class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string s = countAndSay(n-1)+"#";
        string x = "";
        int cnt = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]) cnt++;
            else{
                x += to_string(cnt) + s[i-1];
                cnt = 1;
            }
        }
        return x;
    }
};