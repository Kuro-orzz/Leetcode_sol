#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int dist(pii a, pii b) {
        return abs(a.fi - b.fi) + abs(a.se - b.se);
    }

    int minimumDistance(string word) {
        int n = word.size();
        unordered_map<char, pii> mp;
        for (char i = 'A'; i <= 'Z'; i++) {
            int idx = i - 'A';
            mp[i] = {idx / 6, idx % 6};
        }
        int dp[26][26][n];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 1; k < n; k++) {
                    dp[i][j][k] = 1e9;
                }
            }
        }
        for (int k = 1; k < n; k++) {
            int t = word[k] - 'A';
            int prev = word[k-1] - 'A';
            for (int i = 0; i < 26; i++) {
                dp[t][prev][k] = min(dp[t][prev][k], dp[i][prev][k-1] + dist(mp[i + 'A'], mp[t + 'A']));
                dp[prev][t][k] = min(dp[prev][t][k], dp[prev][i][k-1] + dist(mp[i + 'A'], mp[t + 'A']));
                dp[t][i][k] = min(dp[t][i][k], dp[prev][i][k-1] + dist(mp[prev + 'A'], mp[t + 'A']));
                dp[i][t][k] = min(dp[i][t][k], dp[i][prev][k-1] + dist(mp[prev + 'A'], mp[t + 'A']));
            }
        }
        int ans = 1e9;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                ans = min(ans, dp[i][j][n-1]);
            }
        }
        return ans;
    }
};