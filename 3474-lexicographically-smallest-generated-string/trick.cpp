#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        string ans(n + m - 1, '@');
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') continue;
            for (int j = i; j < i + m; j++) {
                if (ans[j] != '@' && ans[j] != str2[j-i]) return "";
                ans[j] = str2[j-i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') continue;
            bool flag = false;
            int idx = -1;
            for (int j = i + m - 1; j >= i; j--) {
                char current = (ans[j] == '@') ? 'a' : ans[j];
                if (current != str2[j-i]) flag = true;
                if (idx == -1 && ans[j] == '@') idx = j;
            }
            if (flag) continue;
            else if (idx != -1) {
                ans[idx] = 'b';
            } else {
                return "";
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == '@') ans[i] = 'a';
        }
        return ans;
    }
};