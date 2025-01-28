class Solution {
public:
    int n, m;
    vector<vector<int>> image, vis;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    bool isValid(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void dfs(int x, int y, int oldColor, int newColor){
        image[x][y] = newColor;
        vis[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int u = x + dx[i];
            int v = y + dy[i];
            if(isValid(u, v) && !vis[u][v] && image[u][v] == oldColor)
                dfs(u, v, oldColor, newColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        this->image = image;
        n = image.size();
        m = image[0].size();
        vis.resize(n, vector<int>(m, 0));
        dfs(sr, sc, image[sr][sc], color);
        return this->image;
    }
};