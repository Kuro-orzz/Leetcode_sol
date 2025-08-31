#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        pii cur = {0, 0};
        vector<int> ans;
        int cnt = 0;
        while (ans.size() < n * m) {
            // up
            if (cnt % 2 == 0) {
                while (cur.fi >= 0 && cur.se < m) {
                    ans.push_back(mat[cur.fi][cur.se]);
                    cur.fi--; cur.se++;
                }
                cur.fi++;
                if (cur.se == m) cur.fi++, cur.se--;
            } else { // down
                while (cur.fi < n && cur.se >= 0) {
                    ans.push_back(mat[cur.fi][cur.se]);
                    cur.fi++; cur.se--;
                }
                cur.se++;
                if (cur.fi == n) cur.fi--, cur.se++;
            }
            cnt++;
        }
        return ans;
    }
};