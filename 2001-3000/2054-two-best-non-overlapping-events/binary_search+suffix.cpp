class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), [&](vector<int> &a, vector<int> &b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });
        int cur_mx = INT_MIN;
        map<int, int> mp;
        for (int i = n-1; i >= 0; i--) {
            cur_mx = max(cur_mx, events[i][2]);
            mp[events[i][0]] = cur_mx;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a = events[i][2];
            int b = 0;
            auto it = mp.upper_bound(events[i][1]);
            if (it != mp.end()) b = (*it).second;
            ans = max(ans, a + b);
        }
        return ans;
    }
};