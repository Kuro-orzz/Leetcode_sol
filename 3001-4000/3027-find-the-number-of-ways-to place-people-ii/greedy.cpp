class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), cmp);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (points[i][0] <= points[j][0] && points[i][1] >= points[j][1]) {
                    bool flag = true;
                    for (int k = i+1; k < j; k++) {
                        if (k == i || k == j) continue;
                        if (points[k][0] >= points[i][0] && points[k][0] <= points[j][0]
                        && points[k][1] <= points[i][1] && points[k][1] >= points[j][1]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) ans++;
                }
            }
        }
        return ans;
    }
};