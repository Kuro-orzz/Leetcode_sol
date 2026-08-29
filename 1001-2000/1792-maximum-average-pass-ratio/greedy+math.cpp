#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, pii>> pq;
        for (int i = 0; i < n; i++) {
            double a = classes[i][0];
            double b = classes[i][1];
            pq.push({(a+1)/(b+1) - a/b, {a, b}});
        }
        for (int i = 0; i < extraStudents; i++) {
            pair<double, pii> tmp = pq.top(); pq.pop();
            double a = tmp.se.fi + 1;
            double b = tmp.se.se + 1;
            pq.push({(a+1)/(b+1) - a/b, {a, b}});
        }
        double ans = 0;
        while (!pq.empty()) {
            ans += (double)pq.top().se.fi / pq.top().se.se;
            pq.pop();
        }
        return ans / n;
    }
};