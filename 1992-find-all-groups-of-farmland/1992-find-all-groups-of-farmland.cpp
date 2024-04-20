class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> ans;
        bool visited[n][m];
        memset(visited, false, sizeof visited);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(land[i][j] && !visited[i][j]){
                    int x = i, y = j;
                    while(x+1 < n && land[x+1][j] && !visited[x+1][y])
                        x++;
                    while(y+1 < m && land[i][y+1] && !visited[i][y+1])
                        y++;
                    for(int k = i; k <= x; k++)
                        for(int t = j; t <= y; t++)
                            visited[k][t] = true;
                    ans.push_back({i, j, x, y});
                }
            }
        return ans;
    }
};