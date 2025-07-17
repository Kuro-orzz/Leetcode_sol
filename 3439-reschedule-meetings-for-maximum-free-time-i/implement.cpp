class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int cur = 0;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            v.push_back(startTime[i] - cur);
            cur = endTime[i];
        }
        v.push_back(eventTime - cur);
        long long ans = 0, sum = 0;
        for (int i = 0; i < (int)v.size(); i++) {
            sum += v[i];
            ans = max(ans, sum);
            if (i >= k) sum -= v[i-k];
        }
        return ans;
    }
};