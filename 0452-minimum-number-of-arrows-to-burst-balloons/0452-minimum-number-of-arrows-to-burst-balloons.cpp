class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 1;
        vector<int> pre = points[0];
        for(int i = 1; i < points.size(); i++){
            if(pre[1] < points[i][0]){
                ans++;
                pre = points[i];
                continue;
            }
            pre[0] = max(pre[0], points[i][0]);
            pre[1] = min(pre[1], points[i][1]);
        }
        return ans;
    }
};