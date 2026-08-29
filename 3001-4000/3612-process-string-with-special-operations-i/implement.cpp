class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (isalpha(s[i])) {
                ans += s[i];
            } else if (s[i] == '*') {
                if (ans != "") ans.pop_back();
            } else if (s[i] == '#') {
                ans += ans;
            } else if (s[i] == '%') {
                reverse(ans.begin(), ans.end());
            }
        }
        return ans;
    }
};