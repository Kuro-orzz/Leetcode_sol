class Solution {
public:
    int calc(char a, char b) {
        if (a <= b) return b - a;
        return 26 - a + b;
    }

    long long countPairs(vector<string>& words) {
        int n = words.size();
        int m = words[0].size();
        map<vector<int>, int> mp;
        for (int i = 0; i < n; i++) {
            vector<int> val;
            for (int j = 1; j < m; j++) {
                val.push_back(calc(words[i][j-1], words[i][j]));
            }
            mp[val]++;
        }
        long long ans = 0;
        for (auto &it : mp) {
            if (it.second > 1) ans += 1ll * it.second * (it.second - 1) / 2;
        }
        return ans;
    }
};