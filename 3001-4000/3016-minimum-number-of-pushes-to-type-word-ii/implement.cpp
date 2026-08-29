class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26, 0);
        for (char &c : word) {
            cnt[c-'a']++;
        }
        sort(cnt.begin(), cnt.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (i < 8) ans += cnt[i];
            else if (i < 16) ans += cnt[i] * 2;
            else if (i < 24) ans += cnt[i] * 3;
            else ans += cnt[i] * 4;
        }
        return ans;
    }
};