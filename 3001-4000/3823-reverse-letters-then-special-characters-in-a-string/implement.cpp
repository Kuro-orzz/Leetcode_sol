class Solution {
public:
    string reverseByType(string s) {
        int n = s.size();
        vector<int> norm, special;
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                norm.push_back(i);
            } else {
                special.push_back(i);
            }
        }
        string ans = s;
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ans[i] = s[norm.back()];
                norm.pop_back();
            } else {
                ans[i] = s[special.back()];
                special.pop_back();
            }
        }
        return ans;
    }
};