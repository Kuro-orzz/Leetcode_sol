class Solution {
public:
    bool visited[100001];
    vector<pair<int, int>> adj[100001];
    int scc[100001];
    int value[100001];
    int tmp = INT_MAX;
    
    void dfs(int u, int scc_num, vector<int> &vi){
        visited[u] = true;
        scc[u] = scc_num;
        vi.push_back(u);
        for(pair<int, int> v : adj[u]){
            tmp = tmp & v.second;
            if(!visited[v.first]){
                dfs(v.first, scc_num, vi);
            }
        }
    }
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> ans;
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        for(int i = 0; i < n; i++){
            tmp = INT_MAX;
            vector<int> v;
            if(!visited[i])
                dfs(i, i, v);
            for(int x : v)
                value[x] = tmp;
        }
        for(int i = 0; i < query.size(); i++){
            if(scc[query[i][0]] != scc[query[i][1]])
                ans.push_back(-1);
            else if(query[i][0] == query[i][1])
                ans.push_back(0);
            else{
                if(value[query[i][0]] != INT_MAX)
                    ans.push_back(value[query[i][0]]);
                else
                    ans.push_back(-1);
            }
        }        
        return ans;
    }
};