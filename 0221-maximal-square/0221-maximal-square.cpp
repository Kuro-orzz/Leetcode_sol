class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(n == 1 || m == 1){
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(matrix[i][j] == '1')
                        return 1;
            return 0;
        }
        int ans = 0;
        bool kt = true;
        vector<vector<int>> dp(n, vector<int> (m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                dp[i][j] = matrix[i][j]-'0';
                if(dp[i][j] == 1){
                    ans = 1;
                    kt = false;
                }
            }
        while(!kt){
            n--;
            m--;
            kt = true;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++){
                    if(dp[i][j] == dp[i][j+1] && dp[i][j] == dp[i+1][j] && dp[i][j] == dp[i+1][j+1])
                        dp[i][j]++;
                    if(kt && dp[i][j] == ans+1){
                        ans++;
                        kt = false;
                    }
                }
        }
        return ans*ans;
    }
};