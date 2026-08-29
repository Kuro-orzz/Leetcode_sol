class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        set<int> vis_set;
        vector<int> vis(n, 0), d(n, -1);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        d[0] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == n-1) return d[u];
            
            if (vis_set.find(arr[u]) == vis_set.end()) {
                for (int &x : mp[arr[u]]) {
                    if (!vis[x]) {
                        vis[x] = 1;
                        d[x] = d[u] + 1;
                        q.push(x);
                    }
                }
                vis_set.insert(arr[u]);
            }
            if (u + 1 < n && !vis[u+1]) {
                vis[u+1] = 1;
                d[u+1] = d[u] + 1;
                q.push(u+1);
            }
            if (u - 1 >= 0 && !vis[u-1]) {
                vis[u-1] = 1;
                d[u-1] = d[u] + 1;
                q.push(u-1);
            }
        }
        return -1;
    }
};