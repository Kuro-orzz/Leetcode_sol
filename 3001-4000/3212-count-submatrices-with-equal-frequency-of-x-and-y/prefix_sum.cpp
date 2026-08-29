#define ll long long

class Solution {
public:
    vector<vector<ll>> prefix_2d_init(int n, int m, const vector<vector<char>> &a) {
        vector<vector<ll>> pref(n+1, vector<ll>(m+1, 1e9));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i-1][j-1] == 'X') {
                    if (pref[i][j] == 1e9) pref[i][j] = 0;
                    pref[i][j]++;
                } else if (a[i-1][j-1] == 'Y') {
                    if (pref[i][j] == 1e9) pref[i][j] = 0;
                    pref[i][j]--;
                }
                if (pref[i-1][j] != 1e9 || pref[i][j-1] != 1e9 || pref[i-1][j-1] != 1e9) {
                    if (pref[i][j] == 1e9) pref[i][j] = 0;
                    if (pref[i-1][j] != 1e9) pref[i][j] += pref[i-1][j];
                    if (pref[i][j-1] != 1e9) pref[i][j] += pref[i][j-1];
                    if (pref[i-1][j-1] != 1e9) pref[i][j] -= pref[i-1][j-1];
                }
            }
        }
        return pref;
    }

    ll get(const vector<vector<ll>> &pref, int a, int b, int c, int d) {
        return pref[c][d]-pref[c][b-1]-pref[a-1][d]+pref[a-1][b-1];
    }

    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<ll>> pref = prefix_2d_init(n, m, grid);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!pref[i][j]) ans++;
            }
        }
        return ans;
    }
};