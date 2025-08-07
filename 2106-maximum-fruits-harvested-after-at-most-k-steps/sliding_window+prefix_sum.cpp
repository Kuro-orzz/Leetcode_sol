#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int init = 0;
        vector<pii> left, right;
        right.push_back({startPos, 0});
        for (auto it : fruits) {
            if (it[0] < startPos) left.push_back({it[0], it[1]});
            else if (it[0] > startPos) right.push_back({it[0], it[1]});
            else init += it[1];
        }
        left.push_back({startPos, 0});
        for (int i = (int)left.size()-2; i >= 0; i--) left[i].se += left[i+1].se;
        for (int i = 1; i < (int)right.size(); i++) right[i].se += right[i-1].se;
        int ans = 0;
        // startPos -> leftPos -> rightPos
        int l = 0, r = 1;
        while (l < left.size() && startPos - left[l].fi > k) l++;
        if (l < left.size()) ans = max(ans, left[l].se);
        for (; l < (int)left.size(); l++) {
            if (startPos + right[r-1].fi - 2 * left[l].fi > k) continue;
            while (r < right.size() && startPos + right[r].fi - 2 * left[l].fi <= k) r++;
            ans = max(ans, left[l].se + right[r-1].se);
        }
        // startPos -> rightPos -> leftPos
        l = 0, r = 1;
        while (l < left.size() && startPos - left[l].fi > k) l++;
        if (l < left.size()) ans = max(ans, left[l].se);
        for (; l < (int)left.size(); l++) {
            if (2 * right[r-1].fi - startPos - left[l].fi > k) continue;
            while (r < right.size() && 2 * right[r].fi - startPos - left[l].fi <= k) r++;
            ans = max(ans, left[l].se + right[r-1].se);
        }
        return ans + init;
    }
};