class Solution {
public:
    vector<int> a;
    vector<vector<vector<int>>> dp;

    int calc(int i, int j, int turn) {
        if (i > j) return 0;
        if (dp[i][j][turn] != -1) return dp[i][j][turn]; 
        int t1 = a[i] - calc(i+1, j, !turn);
        int t2 = a[j] - calc(i, j-1, !turn);
        return dp[i][j][turn] = max(t1, t2);
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        this->a = piles;
        dp.resize(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return calc(0, n-1, 0) >= 0;
    }
};