class Solution {
public:
    vector<vector<int>> preprocess(int n, int k, int m) {
        vector<vector<int>> C(n+1, vector<int>(k+1));
        for (int i = 0; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= min(i, k); j++) {
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % m;
            }
        }
        return C;
    }

    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<vector<int>> C = preprocess(n-1, n-1, 10);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += C[n-1][i] * nums[i];
        }
        return ans % 10;
    }
};