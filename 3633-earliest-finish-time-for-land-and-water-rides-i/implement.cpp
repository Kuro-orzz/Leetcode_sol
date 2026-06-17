class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int startWater = max(landStartTime[i] + landDuration[i], waterStartTime[j]);
                ans = min(ans, startWater + waterDuration[j]);
                int startLand = max(waterStartTime[j] + waterDuration[j], landStartTime[i]);
                ans = min(ans, startLand + landDuration[i]);
            }
        }
        return ans;
    }
};