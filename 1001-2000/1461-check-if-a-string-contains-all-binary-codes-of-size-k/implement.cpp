class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        vector<int> vis(1 << k);
        for (int i = k; i <= n; i++) {
            bitset<20> b(s.substr(i-k, k));
            vis[b.to_ullong()] = 1;
        }
        for (int x : vis) {
            if (!x) return false;
        }
        return true;
    }
};