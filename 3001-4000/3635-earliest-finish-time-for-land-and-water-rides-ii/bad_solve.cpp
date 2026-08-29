#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    static bool cmp(pii &a, pii &b) {
        if (a.fi + a.se == b.fi + b.se) return a < b;
        return a.fi + a.se < b.fi + b.se;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        vector<int> mnPrefLandDuration(n), mnPrefWaterDuration(m);
        vector<int> mnSuffLandEndTime(n), mnSuffWaterEndTime(m);
        vector<pii> sortedLandStart(n), sortedWaterStart(m);
        vector<pii> sortedLandEnd(n), sortedWaterEnd(m);
        for (int i = 0; i < n; i++) {
            sortedLandStart[i] = {landStartTime[i], landDuration[i]};
            sortedLandEnd[i] = {landStartTime[i], landDuration[i]};
        }
        for (int i = 0; i < m; i++) {
            sortedWaterStart[i] = {waterStartTime[i], waterDuration[i]};
            sortedWaterEnd[i] = {waterStartTime[i], waterDuration[i]};
        }
        sort(sortedLandStart.begin(), sortedLandStart.end());
        sort(sortedWaterStart.begin(), sortedWaterStart.end());
        sort(sortedLandEnd.begin(), sortedLandEnd.end(), cmp);
        sort(sortedWaterEnd.begin(), sortedWaterEnd.end(), cmp);
        for (int i = 0; i < n; i++) {
            if (!i) mnPrefLandDuration[i] = sortedLandStart[i].se;
            else mnPrefLandDuration[i] = min(mnPrefLandDuration[i-1], sortedLandStart[i].se); 
            int j = n-i-1;
            if (j == n-1) mnSuffLandEndTime[j] = sortedLandStart[j].fi + sortedLandStart[j].se;
            else mnSuffLandEndTime[j] = min(mnSuffLandEndTime[j+1], sortedLandStart[j].fi + sortedLandStart[j].se);
        }
        for (int i = 0; i < m; i++) {
            if (!i) mnPrefWaterDuration[i] = sortedWaterStart[i].se;
            else mnPrefWaterDuration[i] = min(mnPrefWaterDuration[i-1], sortedWaterStart[i].se);
            int j = m-i-1;
            if (j == m-1) mnSuffWaterEndTime[j] = sortedWaterStart[j].fi + sortedWaterStart[j].se;
            else mnSuffWaterEndTime[j] = min(mnSuffWaterEndTime[j+1], sortedWaterStart[j].fi + sortedWaterStart[j].se);
        }
        int ans = 1e9;
        int p1 = 0, p2 = 0;
        for (int i = 0; i < n; i++) {
            while (p1 < m && sortedWaterStart[p1].fi < sortedLandEnd[i].fi + sortedLandEnd[i].se) p1++;
            int t = 1e9;
            if (p1) {
                t = min(t, sortedLandEnd[i].fi + sortedLandEnd[i].se + mnPrefWaterDuration[p1-1]);
            }
            if (p1 != m) {
                t = min(t, mnSuffWaterEndTime[p1]);
            }
            ans = min(ans, t);
        }
        for (int i = 0; i < m; i++) {
            while (p2 < n && sortedLandStart[p2].fi < sortedWaterEnd[i].fi + sortedWaterEnd[i].se) p2++;
            int t = 1e9;
            if (p2) {
                t = min(t, sortedWaterEnd[i].fi + sortedWaterEnd[i].se + mnPrefLandDuration[p2-1]);
            }
            if (p2 != n) {
                t = min(t, mnSuffLandEndTime[p2]);
            }
            ans = min(ans, t);
        }

        return ans;
    }
};