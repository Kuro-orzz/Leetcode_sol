class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<int> v(700);
        for (size_t i = 0; i < words.size(); i++) {
            char c1 = words[i][0]-'a', c2 = words[i][1]-'a';
            v[c1 * 26 + c2]++;
        }
        bool odd = false;
        int ans = 0;
        for (int i = 0; i < 700; i++) {
            if (!v[i]) continue;
            int t1 = i % 26, t2 = i / 26;
            if (i == t1 * 26 + t2) {
                ans += v[i] / 2 * 2;
                if (v[i] % 2) odd = true;
            } else {
                ans += min(v[i], v[t1 * 26 + t2]);
            }
        }
        return (ans + odd) * 2;
    }
};