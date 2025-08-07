class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        char curChar = '\0';
        int cnt = 0;
        for (char c : s) {
            if (c == curChar) cnt++;
            else cnt = 1, curChar = c;
            if (cnt < 3) ans += c;
        }
        return ans;
    }
};