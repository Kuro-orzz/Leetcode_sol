class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int cnt_neg = 0, cnt_zero = 0;
        int mn = INT_MAX;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < 0) cnt_neg++;
                else if (matrix[i][j] == 0) cnt_zero++;
                mn = min(mn, abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }
        if (cnt_neg % 2 == 0 || cnt_zero) return sum;
        cout << mn;
        return sum - 2 * mn;
    }
};