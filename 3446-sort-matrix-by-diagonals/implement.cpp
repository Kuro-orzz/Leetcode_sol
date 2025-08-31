#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            pii cur = {i, 0};
            vector<int> v;
            while (cur.fi < n && cur.se < n) {
                v.push_back(grid[cur.fi][cur.se]);
                cur.fi++; cur.se++;
            }
            sort(v.begin(), v.end(), greater<int>());
            do {
                cur.fi--; cur.se--;
                grid[cur.fi][cur.se] = v.back();
                v.pop_back();
            } while (cur.fi != i && cur.se != 0);
        }
        
        for (int j = 1; j < n; j++) {
            pii cur = {0, j};
            vector<int> v;
            while (cur.fi < n && cur.se < n) {
                v.push_back(grid[cur.fi][cur.se]);
                cur.fi++; cur.se++;
            }
            sort(v.begin(), v.end());
            do {
                cur.fi--; cur.se--;
                grid[cur.fi][cur.se] = v.back();
                v.pop_back();
            } while (cur.fi != 0 && cur.se != j);
        }

        return grid;
    }
};