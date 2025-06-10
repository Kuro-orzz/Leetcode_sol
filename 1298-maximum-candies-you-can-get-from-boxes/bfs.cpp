class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<int> curBox(n), curKey(n);
        queue<int> q;
        unordered_set<int> s;
        int ans = 0;
        for (int i = 0; i < n; i++) s.insert(i);
        for (int x : initialBoxes) curBox[x] = 1;
        for (int i = 0; i < n; i++) {
            if (curBox[i] && status[i]) {
                ans += candies[i];
                q.push(i);
                s.erase(i);
            }
        }
        // open box bfs
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int x : containedBoxes[u]) curBox[x] = 1;
            for (int x : keys[u]) curKey[x] = 1;
            vector<int> listErase;
            for (int x : s) {
                if (curBox[x] && (curKey[x] || status[x])) {
                    ans += candies[x];
                    status[x] = 1;
                    q.push(x);
                    listErase.push_back(x);
                }
            }
            for (int x : listErase) s.erase(x);
        }
        return ans;
    }
};