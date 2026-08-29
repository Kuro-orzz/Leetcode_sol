class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> pref(n+1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + (customers[i-1] == 'Y' ? 1 : 0);
        }
        int mn_pen = INT_MAX;
        int ans = -1;
        for (int i = 0; i <= n; i++) {
            if (mn_pen > i - pref[i] + pref[n] - pref[i]) {
                ans = i;
                mn_pen = i - pref[i] + pref[n] - pref[i];
            }
        }
        return ans;
    }
};