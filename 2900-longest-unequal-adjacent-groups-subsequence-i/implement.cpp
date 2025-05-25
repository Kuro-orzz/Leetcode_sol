#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> a, b;
        int t1 = 0, t2 = 1;
        for (int i = 0; i < n; i++) {
            if (groups[i] == t1) {
                a.push_back(words[i]);
                t1 ^= 1;
            }
            if (groups[i] == t2) {
                b.push_back(words[i]);
                t2 ^= 1;
            }
        }
        if (a.size() > b.size()) return a;
        return b;
    }
};