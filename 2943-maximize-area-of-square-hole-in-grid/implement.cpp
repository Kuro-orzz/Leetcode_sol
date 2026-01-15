class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int t1 = 1, t2 = 1;
        int cnt1 = 1, cnt2 = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i-1] + 1 == hBars[i]) cnt1++;
            else cnt1 = 1;
            t1 = max(t1, cnt1);
        }
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i-1] + 1 == vBars[i]) cnt2++;
            else cnt2 = 1;
            t2 = max(t2, cnt2);
        }
        return (min(t1, t2) + 1) * (min(t1, t2) + 1);
    }
};