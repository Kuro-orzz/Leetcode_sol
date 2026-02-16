class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<int> ans = {-1, -1};
        int cur_quality = -1;
        for (int i = 0; i < towers.size(); i++) {
            int d = abs(center[0] - towers[i][0]) + abs(center[1] - towers[i][1]);
            if (d > radius || towers[i][2] < cur_quality) continue;
            if (towers[i][2] > cur_quality) {
                ans = {towers[i][0], towers[i][1]};
                cur_quality = max(cur_quality, towers[i][2]);
            } else if (towers[i][0] < ans[0] || (towers[i][0] == ans[0] && towers[i][1] < ans[1])) {
                ans = {towers[i][0], towers[i][1]};
            }
        }
        return ans;
    }
};