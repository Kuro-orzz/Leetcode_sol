class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<pair<char, int>> target = {{'a', 1}, {'b', 1}, {'l', 2}, {'o', 2}, {'n', 1}};
        vector<int> cnt(26, 0);
        for (char &c : text) {
            cnt[c-'a']++;
        }
        int ans = 1e9;
        for (auto it : target) {
            ans = min(ans, cnt[it.first-'a'] / it.second);
        }
        return ans;
    }
};