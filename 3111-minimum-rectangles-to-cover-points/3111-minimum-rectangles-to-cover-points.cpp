class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int ans = 0;
        int start = -1, end = -1;
        for(int i = 0; i < points.size(); i++){
            if(end < points[i][0]){
                ans++;
                start = points[i][0];
                end = start + w;
            }
            else continue;
        }
        return ans;
    }
};