class Solution {
public:
    string word1, word2;
    vector<vector<int>> dp;

    int distance(int i, int j){
        if(i == 0 && j == 0) return dp[i][j] = 0;
        if(i == 0 || j == 0) return dp[i][j] = max(i, j);
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i-1] == word2[j-1])
            return dp[i][j] = distance(i-1, j-1);
        return dp[i][j] = min({distance(i-1, j), distance(i, j-1), distance(i-1, j-1)})+1;
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        this->word1 = word1;
        this->word2 = word2;
        dp.resize(n+1, vector<int>(m+1, -1));
        return distance(n, m);
    }
};