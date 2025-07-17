class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < (int)s.size(); i++) {
            mp[s[i]]++;
            int x = abs(mp['N'] - mp['S']);
            int y = abs(mp['E'] - mp['W']);
            int dist = x + y + min(2 * k, i+1-x-y);
            ans = max(ans, dist);
        }
        return ans;
    }
};