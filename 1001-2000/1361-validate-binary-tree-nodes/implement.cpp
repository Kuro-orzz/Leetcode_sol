class Solution {
public:
    int bfs(int s, int n, vector<int> &l, vector<int> &r) {
        vector<int> vis(n, 0);
        int cnt = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            vis[u] = 1;
            cnt++;
            if (l[u] != -1 && !vis[l[u]]) q.push(l[u]);
            if (r[u] != -1 && !vis[r[u]]) q.push(r[u]);
        }
        return cnt;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> par(n, -1);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (par[leftChild[i]] != -1) return false;
                par[leftChild[i]] = i;
            }
            if (rightChild[i] != -1) {
                if (par[rightChild[i]] != -1) return false;
                par[rightChild[i]] = i;
            }
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (par[i] == -1) root = i;
        }
        if (root == -1) return false;
        return bfs(root, n, leftChild, rightChild) == n;
    }
};