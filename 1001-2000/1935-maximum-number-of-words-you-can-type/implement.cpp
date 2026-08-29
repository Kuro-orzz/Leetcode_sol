class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> brokenKey(26);
        for (char &c : brokenLetters) {
            brokenKey[c - 'a'] = 1;
        }
        stringstream ss(text);
        string s;
        int ans = 0;
        while (ss >> s) {
            bool flag = true;
            for (char &c : s) {
                if (brokenKey[c - 'a']) flag = false;
            }
            if (flag) ans++;
        }
        return ans;
    }
};