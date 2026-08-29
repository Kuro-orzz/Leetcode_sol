class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i = 2; i <= n; i++) {
            string rev = s;
            for (char &c : rev) {
                if (c == '0') c = '1';
                else c = '0';
            }
            reverse(rev.begin(), rev.end());
            s += '1' + rev;
        }
        return s[k-1];
    }
};