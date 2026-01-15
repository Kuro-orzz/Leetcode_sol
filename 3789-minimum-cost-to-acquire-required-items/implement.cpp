class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        if (costBoth < cost1 + cost2) {
            int mn = min(need1, need2);
            ans += 1ll * mn * costBoth;
            need1 -= mn;
            need2 -= mn;
        }
        if (need1) {
            if (costBoth < cost1) {
                ans += 1ll * need1 * costBoth;
            } else {
                ans += 1ll * need1 * cost1;
            }
        }
        if (need2) {
            if (costBoth < cost2) {
                ans += 1ll * need2 * costBoth;
            } else {
                ans += 1ll * need2 * cost2;
            }
        }
        return ans;
    }
};