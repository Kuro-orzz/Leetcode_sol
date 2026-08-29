#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<pii> event;
        for (int i = 0; i < n; i++) {
            event.push_back({trips[i][1], trips[i][0]});
            event.push_back({trips[i][2], -trips[i][0]});
        }
        sort(event.begin(), event.end());
        int curPass = 0;
        for (int i = 0; i < event.size(); i++) {
            curPass += event[i].se;
            if (curPass > capacity) return false;
        }
        return true;
    }
};