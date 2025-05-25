class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int N, int x, int y, int &cnt) {
        if (N == 0) {
            ans[x][y] = cnt++;
            return;
        }
        solve(N-1, x, y+(1<<N-1), cnt);
        solve(N-1, x+(1<<N-1), y+(1<<N-1), cnt);
        solve(N-1, x+(1<<N-1), y, cnt);
        solve(N-1, x, y, cnt);
    }
    
    vector<vector<int>> specialGrid(int N) {
        int n = (1 << N);
        ans.resize(n, vector<int>(n));
        int cnt = 0;
        solve(N, 0, 0, cnt);
        return ans;
    }
};