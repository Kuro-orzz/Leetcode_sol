class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < roads.size(); i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; i++)
            pq.push({adj[i].size(), i});
        vector<int> v(n);
        int cnt = n;
        while(!pq.empty()){
            v[pq.top().second] = cnt--;
            pq.pop();
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += adj[i].size()*v[i];
        }
        return ans;
    }
};