#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    static const int N = 10;
    int a[N][N], ans[N][N];
    unordered_set<int> row[N], col[N], group[N][N];
    vector<pii> pos;
    bool solved = false;
    
    void res() {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                ans[i][j] = a[i][j];
            }
        }
    }

    int gr(int i) { return (i-1)/3; }
    
    void add(int i, int j, int x) {
        a[i][j] = x;
        row[i].insert(x);
        col[j].insert(x);
        group[gr(i)][gr(j)].insert(x);
    }
    
    void del(int i, int j, int x) {
        a[i][j] = 0;
        row[i].erase(x);
        col[j].erase(x);
        group[gr(i)][gr(j)].erase(x);
    }
    
    void backtrack(int p) {
        if (p == pos.size()) {
            res();
            solved = true;
            return;
        }
        auto [i, j] = pos[p];
        for (int x = 1; x <= 9; x++) {
            if (row[i].count(x) || col[j].count(x)) continue;
            if (group[gr(i)][gr(j)].count(x)) continue;
            add(i, j, x);
            backtrack(p+1);
            if (solved) return;
            del(i, j, x);
        }
    }
    
    void preprocess() {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                row[i].insert(a[i][j]);
                col[j].insert(a[i][j]);
                group[gr(i)][gr(j)].insert(a[i][j]);
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                if (board[i-1][j-1] == '.') a[i][j] = 0;
                else a[i][j] = board[i-1][j-1] - '0';
                if (!a[i][j]) pos.emplace_back(i, j);
            }
        }
        preprocess();
        backtrack(0);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                board[i][j] = a[i+1][j+1] + '0';
            }
        }
    }
};