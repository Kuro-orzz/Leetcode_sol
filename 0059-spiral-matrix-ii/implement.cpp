#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int cnt = 0;
        pii pos = {0, -1};
        while (cnt < n * n) {
            while (pos.se + 1 < n && !ans[pos.fi][pos.se+1]) {
                ans[pos.fi][++pos.se] = ++cnt;
            }
            while (pos.fi + 1 < n && !ans[pos.fi+1][pos.se]) {
                ans[++pos.fi][pos.se] = ++cnt;
            }
            while (pos.se - 1 >= 0 && !ans[pos.fi][pos.se-1]) {
                ans[pos.fi][--pos.se] = ++cnt;
            }
            while (pos.fi - 1 >= 0 && !ans[pos.fi-1][pos.se]) {
                ans[--pos.fi][pos.se] = ++cnt;
            }        
        }
        return ans;
    }
};