class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end(), [&](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        });
        unordered_set<int> known({0, firstPerson});
        for (int i = 0; i < m;) {
            map<int, vector<int>> adj;
            do {
                adj[meetings[i][0]].push_back(meetings[i][1]);
                adj[meetings[i][1]].push_back(meetings[i][0]);
                i++;
            } while (i < m && i && meetings[i][2] == meetings[i-1][2]);
            unordered_set<int> visited;
            for (auto &[val, v] : adj) {
                if (known.find(val) == known.end()) continue;
                queue<int> q({val});
                while (!q.empty()) {
                    int v = q.front(); q.pop();
                    known.insert(v);
                    for (int u : adj[v]) {
                        if (visited.find(u) != visited.end()) continue;
                        q.push(u);
                        visited.insert(u);
                    }
                }
            }
        }
        vector<int> ans;
        for (int x : known) ans.push_back(x);
        sort(ans.begin(), ans.end());
        return ans;
    }
};