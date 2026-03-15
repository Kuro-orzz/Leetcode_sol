class Solution {
public:
    string smallestString(string s) {
        int n = s.size();
        bool chose = false;
        for (int i = 0; i < n; i++) {
            while (i < n && s[i] > 'a') {
                s[i++]--;
                chose = true;
            }
            if (chose) break;
        }
        if (!chose) s[n-1] = 'z';
        return s;
    }
};