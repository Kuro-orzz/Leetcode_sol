class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lowerCase(26, 0), upperCase(26, 0), failed(26, 0);
        for (char &c : word) {
            if (islower(c)) {
                if (failed[c-'a']) continue;
                if (upperCase[c-'a']) {
                    failed[c-'a'] = 1;
                    continue;
                }
                lowerCase[c-'a'] = 1;
            } else if (isupper(c)) {
                if (failed[c-'A']) continue;
                if (!lowerCase[c-'A']) {
                    failed[c-'A'] = 1;
                    continue;
                }
                upperCase[c-'A'] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lowerCase[i] && upperCase[i] && !failed[i]) ans++;
        }
        return ans;
    }
};