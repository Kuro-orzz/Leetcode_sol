class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int intersect = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int a = max(0, min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]));
                int b = max(0, min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]));
                intersect = max(intersect, min(a, b));
            }
        }
        long long area = 1ll * intersect * intersect;
        return area;
    }
};