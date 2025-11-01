bool operator < (string &a, string &b) {
    if (a.size() < b.size()) return true;
    else if (a.size() > b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < b[i]) return true;
        else if (a[i] > b[i]) return false;
    }
    return false;
}

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string ans = string(n, '9');
        for (int rot = 0; rot <= n; rot++) {
            for (int add1 = 0; add1 <= 10; add1++) {
                for (int add2 = 1; add2 <= 10; add2++) {
                    string tmp = s;
                    for (int idx = 1; idx < n; idx += 2) {
                        tmp[idx] = (tmp[idx] - '0' + a * add1) % 10 + '0';
                    }
                    rotate(tmp.begin(), tmp.begin() + b, tmp.end());
                    for (int idx = 1; idx < n; idx += 2) {
                        tmp[idx] = (tmp[idx] - '0' + a * add2) % 10 + '0';
                    }
                    for (int i = 0; i < rot; i++) {
                        rotate(tmp.begin(), tmp.begin() + b, tmp.end());
                        if (tmp < ans) ans = tmp;
                    }
                    // cout << tmp << '\n';
                }
            }
        }
        return ans;
    }
};