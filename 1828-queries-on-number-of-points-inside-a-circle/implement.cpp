class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            int r = queries[i][2];
            for (auto p : points) {
                int t1 = (x - p[0]) * (x - p[0]);
                int t2 = (y - p[1]) * (y - p[1]);
                double dist = sqrt(t1 + t2);
                if (dist <= r) ans[i]++;
            }
        }
        return ans;
    }
};