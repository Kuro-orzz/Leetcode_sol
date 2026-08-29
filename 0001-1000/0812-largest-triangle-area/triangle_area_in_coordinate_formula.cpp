class Solution {
public:
    // keyword: area of triangle in coordinate geometry
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    double x1y2 = points[i][0] * points[j][1];
                    double x2y3 = points[j][0] * points[k][1];
                    double x3y1 = points[k][0] * points[i][1];
                    double x2y1 = points[j][0] * points[i][1];
                    double x3y2 = points[k][0] * points[j][1];
                    double x1y3 = points[i][0] * points[k][1];
                    double area = 0.5 * abs(x1y2 + x2y3 + x3y1 - x2y1 - x3y2 - x1y3);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};