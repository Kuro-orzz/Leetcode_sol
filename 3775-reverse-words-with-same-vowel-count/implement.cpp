class Solution {
public:
    bool isVowel(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u'; }

    string reverseWords(string s) {
        stringstream ss(s);
        string ans = "", x;
        int cntFirst = 0;
        for (int i = 0; ss >> x; i++) {
            int cnt = 0;
            for (char c : x) if (isVowel(c)) cnt++;
            if (!i) cntFirst = cnt;
            else {
                if (cnt == cntFirst) reverse(x.begin(), x.end());
                ans += ' ';
            }
            ans += x;
        }
        return ans;
    }
};