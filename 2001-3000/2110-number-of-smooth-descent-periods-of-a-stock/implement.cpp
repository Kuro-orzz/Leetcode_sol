class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 0, cnt = 1;
        for (int i = 1; i < n; i++) {
            if (prices[i-1] - 1 == prices[i]) cnt++;
            else {
                ans += 1ll * cnt * (1 + cnt) / 2;
                cnt = 1;
            }
        }
        ans += 1ll * cnt * (1 + cnt) / 2;
        return ans;
    }
};