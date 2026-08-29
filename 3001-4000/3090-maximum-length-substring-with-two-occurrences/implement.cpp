class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0, ans = 0;
        vector<int> cnt(26, 0);
        while (r < n) {
            int k = s[r++] - 'a';
            cnt[k]++;
            while (cnt[k] > 2) cnt[s[l++]-'a']--;
            ans = max(ans, r - l);
        }
        return ans;
    }
};