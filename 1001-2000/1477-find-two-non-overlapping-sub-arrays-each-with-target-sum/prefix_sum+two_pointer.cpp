#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> pref(n+1, 0);
        for (int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + arr[i];
        }
        vector<pii> segment;
        int p1 = 0, p2 = 0;
        while (p2 <= n) {
            while (p2 <= n && pref[p2] - pref[p1] < target) p2++;
            if (p2 <= n && pref[p2] - pref[p1] == target) {
                segment.emplace_back(p1, p2);
            }
            p1++;
        }

        int ans = INT_MAX;
        vector<int> minLen(n+1, INT_MAX);
        for (auto it : segment) {
            minLen[it.se] = it.se - it.fi; 
        }
        for (int i = 1; i <= n; i++) {
            minLen[i] = min(minLen[i-1], minLen[i]);
        }
        for (auto it : segment) {
            if (minLen[it.fi] == INT_MAX) continue;
            ans = min(ans, it.se-it.fi + minLen[it.fi]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};