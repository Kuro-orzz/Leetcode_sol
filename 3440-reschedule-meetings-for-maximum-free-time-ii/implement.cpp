class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        startTime.insert(startTime.begin(), 0);
        startTime.push_back(eventTime);
        endTime.insert(endTime.begin(), 0);
        endTime.push_back(eventTime);
        int n = startTime.size();
        vector<int> mxPref(n), mxSuff(n);
        for (int i = 0; i < n; i++) {
            if (!i) mxPref[i] = 0;
            else mxPref[i] = max(mxPref[i-1], startTime[i] - endTime[i-1]);
            if (!i) mxSuff[n-i-1] = 0;
            else mxSuff[n-i-1] = max(mxSuff[n-i], startTime[n-i] - endTime[n-i-1]);
        }
        int ans = 0;
        for (int i = 1; i < n-1; i++) {
            int len = endTime[i] - startTime[i];
            if (len <= mxPref[i-1] || len <= mxSuff[i+1]) {
                ans = max(ans, startTime[i+1] - endTime[i-1]);
            } else {
                ans = max(ans, startTime[i+1] - endTime[i-1] - len);
            }
        }
        return ans;
    }
};