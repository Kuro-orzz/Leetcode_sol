class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> v(26, 0);
            int cnt = 1, mx = 0;
            for (int j = i; j < n; j++) {
                int k = s[j] - 'a';
                v[k]++;
                if (v[k] > mx) {
                    cnt = 1, mx = v[s[j]-'a'];
                } else if (v[k] == mx) {
                    cnt++;
                }
                if (cnt * mx == j-i+1) {
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};