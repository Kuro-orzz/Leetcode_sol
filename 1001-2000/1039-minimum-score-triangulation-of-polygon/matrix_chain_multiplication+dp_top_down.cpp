/*
    Matrix chain multiplication
    O(n*n*n)
*/
#define ll long long

class Solution {
public:
    vector<int> a;
    vector<vector<int>> dp;

    ll matrix_chain(int i, int j) {
        if (i + 1 == j) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        ll res = 1e18;
        for (int k = i+1; k < j; k++) {
            ll t = matrix_chain(i, k) + matrix_chain(k, j) + a[i] * a[k] * a[j];
            res = min(res, t);
        }
        return dp[i][j] = res;
    }

    int minScoreTriangulation(vector<int>& values) {
        this->a = values;
        int n = a.size();
        dp.resize(n, vector<int>(n, -1));
        return matrix_chain(0, n-1);
    }
};