#define ll long long

class Solution {
public:
    vector<vector<ll>> prefix_2d_init(int n, int m, const vector<vector<int>> &a) {
        vector<vector<ll>> pref(n+1, vector<ll>(m+1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + a[i-1][j-1];
            }
        }
        return pref;
    }

    ll get(const vector<vector<ll>> &pref, int a, int b, int c, int d) {
        return pref[c][d] - pref[c][b-1] - pref[a-1][d] + pref[a-1][b-1];
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<ll>> pref = prefix_2d_init(n, m, grid);
        int k = min(n, m);
        for (int sz = k; sz >= 2; sz--) {
            for (int i = sz; i <= n; i++) {
                for (int j = sz; j <= m; j++) {
                    bool flag = true;
                    int sum = get(pref, i, j-sz+1, i, j);
                    int diag1 = 0, diag2 = 0;
                    for (int pos = 0; pos < sz; pos++) {
                        if ( get(pref, i-pos, j-sz+1, i-pos, j) != sum ) {
                            flag = false;
                            break;
                        }
                        if ( get(pref, i-sz+1, j-pos, i, j-pos) != sum ) {
                            flag = false;
                            break;
                        }
                        diag1 += grid[i-pos-1][j-pos-1];
                        diag2 += grid[i-pos-1][j-sz+pos];
                    }
                    if (diag1 != sum || diag2 != sum) flag = false;
                    if (flag) return sz;
                }
            }
        }
        return 1;
    }
};