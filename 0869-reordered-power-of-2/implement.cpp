class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<map<char, int>> mp;
        int k = 1;
        while (k <= 1e9) {
            mp.push_back({});
            string s = to_string(k);
            for (char c : s) {
                mp.back()[c]++;
            }
            k *= 2;
        }
        map<char, int> t;
        string s = to_string(n);
        for (char c : s) t[c]++;
        for (auto x : mp) {
            if (t == x) return true;
        }
        return false;
    }
};