class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lowerCase(26, 0), upperCase(26, 0);
        for (char &c : word) {
            if (islower(c)) {
                lowerCase[c-'a'] = 1;
            } else {
                upperCase[c-'A'] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lowerCase[i] && upperCase[i]) ans++;
        }
        return ans;
    }
};