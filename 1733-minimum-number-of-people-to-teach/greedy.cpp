class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        // lang[i][j]: user[i] know language j
        vector<vector<int>> lang(m+1, vector<int>(n+1));
        for (int i = 0; i < m; i++) {
            for (int x : languages[i]) {
                lang[i+1][x] = 1;
            }
        }
        set<int> s;
        for (auto &it : friendships) {
            int u = it[0];
            int v = it[1];
            bool flag = false;
            for (int x : languages[u-1]) {
                if (lang[v][x]) flag = true;
            }
            if (!flag) {
                s.insert(u);
                s.insert(v);
            }
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int x : s) {
                if (!lang[x][i]) cnt++;
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};