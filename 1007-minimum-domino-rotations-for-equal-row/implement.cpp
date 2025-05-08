class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = 1e9;
        int cnt[4];
        cnt[0] = cnt[2] = 0;
        cnt[1] = cnt[3] = 1;
        for (int i = 1; i < n; i++) {
            if (cnt[0] != -1 && tops[i] != tops[0]) {
                if (bottoms[i] == tops[0]) cnt[0]++;
                else cnt[0] = -1;
            }
            if (cnt[1] != -1 && tops[i] != bottoms[0]) {
                if (bottoms[i] == bottoms[0]) cnt[1]++;
                else cnt[1] = -1;
            }
            if (cnt[2] != -1 && bottoms[i] != bottoms[0]) {
                if (tops[i] == bottoms[0]) cnt[2]++;
                else cnt[2] = -1;
            }
            if (cnt[3] != -1 && bottoms[i] != tops[0]) {
                if (tops[i] == tops[0]) cnt[3]++;
                else cnt[3] = -1;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (cnt[i] != -1) ans = min(ans, cnt[i]);
        }
        return ans == 1e9 ? -1 : ans;
    }
};