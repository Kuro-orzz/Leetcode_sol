class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;
    stack<int> st;

    bool dfs(int u) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (vis[v] == 1) return false;
            if (!vis[v]) dfs(v);
        }
        st.push(u);
        vis[u] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        vis.resize(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i] && !dfs(i)) return false;
        }
        return st.size() == numCourses;
    }
};