class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        for (int i = 0; i < n; i++) {
            vector<int> v;
            int pos = 0;
            for (int j = m-1; j >= 0; j--) {
                if (boxGrid[i][j] == '.') {
                    v.push_back(j);
                } else if (boxGrid[i][j] == '*') {
                    v.clear();
                    pos = 0;
                } else if (boxGrid[i][j] == '#') {
                    if (v.size() <= pos) continue;
                    swap(boxGrid[i][j], boxGrid[i][v[pos++]]);
                    v.push_back(j);
                }
            }
        }
        vector<vector<char>> ans(m, vector<char>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = boxGrid[n-j-1][i];
            }
        }
        return ans;
    }
};