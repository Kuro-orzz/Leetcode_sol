class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c-'a']++;
        int odd = 0;
        char center = '@';
        string firstHalf = "";
        for (int i = 25; i >= 0; i--) {
            if (cnt[i] % 2) {
                odd++;
                center = (char)(i + 'a');
            }
            cnt[i] /= 2;
            for (int j = 0; j < cnt[i]; j++) {
                firstHalf += (char)(i + 'a');
            }
        }
        if (odd > 1) return "";
        
        // find strictly greater
        int n = s.size();
        int half = n / 2;
        string ans = "";
        int i = 0;
        bool greater = false;
        for (; i < half; i++) {
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
        if (!greater && i == half) {
            string s = ans;
            reverse(s.begin(), s.end());
            string full = ans;
            if (center != '@') full += center;
            full += s;
            if (full > target) return full; 
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
        string secondHalf = ans;
        reverse(secondHalf.begin(), secondHalf.end());
        if (center != '@') ans += center;
        ans += secondHalf;
        return ans;
    }
};