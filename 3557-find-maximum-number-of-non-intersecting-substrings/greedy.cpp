class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        vector<int> v(26, -1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int c = word[i]-'a';
            if (v[c] == -1) {
                v[c] = i;
            } else if (i - v[c] >= 3) {
                ans++;
                v.assign(26, -1);
            }
        }        
        return ans;
    }
};