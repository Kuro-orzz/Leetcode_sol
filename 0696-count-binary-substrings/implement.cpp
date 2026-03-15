class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int ans = 0, prev = 0, cur;
        int cntNum = s[0] - '0';
        for (int i = 0; i < n;) {
            cur = 0;
            while (i < n && s[i]-'0' == cntNum) {
                cur++;
                i++;
            }
            ans += min(prev, cur);
            prev = cur;
            cntNum ^= 1;
        }
        return ans;
    }
};