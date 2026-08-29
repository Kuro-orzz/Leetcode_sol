class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n = s.size();
        long long ans = LLONG_MAX;
        for (int i = 0; i < 26; i++) {
            long long sum = 0;
            for (int j = 0; j < n; j++) {
                if (s[j]-'a' != i) sum += cost[j];
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};