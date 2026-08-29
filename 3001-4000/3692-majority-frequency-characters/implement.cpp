class Solution {
public:
    string majorityFrequencyGroup(string s) {
        int n = s.size();
        vector<int> cnt(26);
        for (char c : s) {
            cnt[c-'a']++;
        }
        vector<int> fre(106);
        for (int x : cnt) {
            if (!x) continue;
            fre[x]++;
        }
        int mx_fre = 0;
        for (int i = 0; i <= 100; i++) {
            if (fre[i] >= fre[mx_fre]) {
                mx_fre = i;
            }
        }
        string ans = "";
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == mx_fre) {
                ans += (char)(i+'a');
            }
        }
        return ans;
    }
};