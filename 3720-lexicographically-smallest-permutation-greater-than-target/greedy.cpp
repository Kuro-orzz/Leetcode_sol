class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        string ans = "";
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; i++) {
            cnt[s[i]-'a']++;
        }
        int i = 0;
        bool greater = false;
        for (; i < n; i++) {
            int k = target[i] - 'a';
            if (cnt[k]) {
                ans += target[i];
                cnt[k]--;
                continue;
            }
            for (int j = k+1; j < 26; j++) {
                if (cnt[j]) {
                    ans += (char)(j + 'a');
                    cnt[j]--;
                    greater = true;
                    break;
                }
            }
            break;
        }
        while (!greater) {
            if (ans.empty()) return "";
            cnt[ans.back()-'a']++;
            ans.pop_back();
            int k = target[--i] - 'a';
            for (int j = k + 1; j < 26; j++) {
                if (cnt[j]) {
                    ans += (char)(j + 'a');
                    cnt[j]--;
                    greater = true;
                    break;
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            while (cnt[i]) {
                ans += (char)(i + 'a');
                cnt[i]--;
            }
        }
        return ans;
    }
};