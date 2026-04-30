#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    map<int, vector<pair<char, char>>> mp = {
        {1, {{'L', 'R'}, {'R', 'L'}}},
        {2, {{'U', 'D'}, {'D', 'U'}}},
        {3, {{'L', 'D'}, {'D', 'L'}}},
        {4, {{'R', 'D'}, {'D', 'R'}}},
        {5, {{'L', 'U'}, {'U', 'L'}}},
        {6, {{'U', 'R'}, {'R', 'U'}}}
    };

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n == 1 && m == 1) return true;
        for (int i = 0; i < 2; i++) {
            pii cur = {0, 0};
            char in = mp[grid[cur.fi][cur.se]][i].fi, out = mp[grid[cur.fi][cur.se]][i].se;
            auto inCase = [&](int num, char c) {
                if (mp[num][0].fi == c) in = c, out = mp[num][0].se;
                else if (mp[num][1].fi == c) in = c, out = mp[num][1].se;
                else in = '@', out = '@';
            };
            int step = 0;
            while (cur != make_pair(n-1, m-1) && step <= n * m) {
                step++;
                if (out == 'D') cur.fi++;
                else if (out == 'U') cur.fi--;
                else if (out == 'L') cur.se--;
                else if (out == 'R') cur.se++;
                if (cur.fi >= 0 && cur.fi < n && cur.se >= 0 && cur.se < m) {}
                else break;

                int num = grid[cur.fi][cur.se];
                if (out == 'D') inCase(num, 'U');
                else if (out == 'U') inCase(num, 'D');
                else if (out == 'L') inCase(num, 'R');
                else if (out == 'R') inCase(num, 'L');
                if (in == '@' || out == '@') break;
                if (cur == make_pair(n-1, m-1)) return true;
            }
        }
        return false;
    }
};