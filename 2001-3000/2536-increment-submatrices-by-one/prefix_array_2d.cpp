#define ll long long

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> pref(n+1, vector<int>(n+1, 0));
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0] + 1;
            int b = queries[i][1] + 1;
            int c = queries[i][2] + 1;
            int d = queries[i][3] + 1;
            pref[c][d] += 1;
            pref[c][b-1] -= 1;
            pref[a-1][d] -= 1;
            pref[a-1][b-1] += 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i) pref[i][j] += pref[i-1][j];
                if (j) pref[i][j] += pref[i][j-1];
                if (i && j) pref[i][j] -= pref[i-1][j-1];
            }
        }
        pref.resize(n);
        for (int i = 0; i < n; i++) {
            pref[i].resize(n);
        }
        return pref;
    }
};