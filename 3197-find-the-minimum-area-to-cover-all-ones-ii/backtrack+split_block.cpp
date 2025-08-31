#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    vector<vector<int>> grid;
    int n, m, ans = 1e9;

    int cal(pii x, pii y) { return (y.fi - x.fi + 1) * (y.se - x.se + 1); }

    vector<pii> minSquare(pii a, pii b) {
        pii mn = {1e9, 1e9}, mx = {0, 0};
        for (int i = a.fi; i <= b.fi; i++) {
            for (int j = a.se; j <= b.se; j++) {
                if (!grid[i][j]) continue;
                mn.fi = min(mn.fi, i);
                mn.se = min(mn.se, j);
                mx.fi = max(mx.fi, i);
                mx.se = max(mx.se, j);
            }
        }
        if (mn == make_pair(1e9, 1e9)) return {};
        return {mn, mx};
    }

    // a: up left
    // b: right down
    // cnt: number of rectangle split
    void backtrack(pii a, pii b, int cnt, int curSum) {
        if (cnt == 3) {
            ans = min(ans, curSum + cal(a, b));
            return;
        }
        // split horizontal
        for (int i = a.fi+1; i <= b.fi; i++) {
            vector<pii> fi_block = minSquare(a, {i-1, b.se});
            vector<pii> se_block = minSquare({i, a.se}, b);
            if (fi_block.empty() || se_block.empty()) break;
            backtrack(fi_block[0], fi_block[1], cnt+1, curSum + cal(se_block[0], se_block[1]));
            backtrack(se_block[0], se_block[1], cnt+1, curSum + cal(fi_block[0], fi_block[1]));
        }

        // split vertical
        for (int i = a.se+1; i <= b.se; i++) {
            vector<pii> fi_block = minSquare(a, {b.fi, i-1});
            vector<pii> se_block = minSquare({a.fi, i}, b);
            if (fi_block.empty() || se_block.empty()) break;
            backtrack(fi_block[0], fi_block[1], cnt+1, curSum + cal(se_block[0], se_block[1]));
            backtrack(se_block[0], se_block[1], cnt+1, curSum + cal(fi_block[0], fi_block[1]));
        }
    }

    int minimumSum(vector<vector<int>>& grid) {
        this->grid = grid;
        this->n = grid.size();
        this->m = grid[0].size();
        vector<pii> k = minSquare({0, 0}, {n-1, m-1});
        backtrack(k[0], k[1], 1, 0);
        return ans;
    }
};