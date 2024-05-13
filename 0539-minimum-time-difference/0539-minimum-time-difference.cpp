class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int ans = INT_MAX;
        int n = timePoints.size();
        for(int i = 1; i < n; i++){
            int j = stoi(timePoints[i-1].substr(0, 2)) * 60 + stoi(timePoints[i-1].substr(3, 2));
            int k = stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3, 2));
            ans = min(ans, k-j);
        }
        int j = stoi(timePoints[0].substr(0, 2)) * 60 + stoi(timePoints[0].substr(3, 2));
        int k = stoi(timePoints[n-1].substr(0, 2)) * 60 + stoi(timePoints[n-1].substr(3, 2));
        ans = min({ans, k-j, 1440-(k-j)});
        return ans;
    }
};