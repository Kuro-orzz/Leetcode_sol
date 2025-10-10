/*
    Matrix chain multiplication
    O(2^n)
*/
#define ll long long

class Solution {
public:
    vector<int> a;

    ll matrix_chain(int i, int j) {
        if (i + 1 == j) {
            return 0;
        }
        ll res = 1e18;
        for (int k = i+1; k < j; k++) {
            ll t = matrix_chain(i, k) + matrix_chain(k, j) + a[i] * a[k] * a[j];
            res = min(res, t);
        }
        return res;
    }

    int minScoreTriangulation(vector<int>& values) {
        this->a = values;
        int n = a.size();
        return matrix_chain(0, n-1);
    }
};