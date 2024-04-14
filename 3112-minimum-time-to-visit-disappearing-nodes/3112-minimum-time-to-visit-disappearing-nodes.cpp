class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int, int>> adj[n];
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        int cnt = 0, pre = 0;
        bool visited[n];
        vector<long long> d(n);
        memset(visited, false, sizeof(visited));
        do{
            pre = cnt;
            for(int i = 0; i < n; i++)
                d[i] = INT_MAX;
            cnt = 0;
            d[0] = 0;
            priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
            pq.push({0, 0});
            while(!pq.empty()){
                long long dist = pq.top().first;
                int u = pq.top().second;
                pq.pop();
                if(visited[u]) continue;
                visited[u] = true;
                for(auto it : adj[u]){
                    int v = it.first;
                    int w = it.second;
                    if(d[v] > d[u] + w){
                        d[v] = d[u] + w;
                        pq.push({d[v], v});
                    }
                }
            }
            memset(visited, false, sizeof(visited));
            for(int i = 0; i < n; i++)
                if(d[i] >= disappear[i]){
                    visited[i] = true;
                    cnt++;
                }
        }while(cnt != pre);
        vector<int> ans;
        ans.push_back(0);
        for(int i = 1; i < n; i++)
            if(d[i] >= disappear[i])
                ans.push_back(-1);
            else
                ans.push_back(d[i]);
        return ans;        
    }
};