class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(10, vector<int>(10)), col(10, vector<int>(10));
        vector<vector<vector<int>>> group(4, vector<vector<int>>(4, vector<int>(10)));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                row[i][board[i][j]-'0']++;
                col[j][board[i][j]-'0']++;
                group[i/3][j/3][board[i][j]-'0']++;

                if (row[i][board[i][j]-'0'] > 1) return false;
                if (col[j][board[i][j]-'0'] > 1) return false;
                if (group[i/3][j/3][board[i][j]-'0'] > 1) return false;
            }
        }
        return true;
    }
};