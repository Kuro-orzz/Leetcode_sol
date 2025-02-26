class Solution {
public:
    vector<vector<int>> adj;
    vector<int> par, amount, dp, leaf;
    
    void dfs(int u, int p = 0){
        par[u] = p;
        int cnt = 0;
        for(int v : adj[u]){
            if(v == p) continue;
            cnt++;
            dfs(v, u);
        }
        if(!cnt) leaf.push_back(u);
    }

    int bfs(int alice, int bob){
        queue<int> q;
        q.push(alice);
        dp[alice] = amount[alice];
        while(!q.empty()){
            int sz = q.size();
            amount[bob] = 0;
            bob = par[bob];
            for(int i = 0; i < sz; i++){
                int u = q.front(); q.pop();
                for(int v : adj[u]){
                    if(v == par[u]) continue;
                    if(v == bob)
                        dp[v] = dp[u] + amount[v]/2;
                    else
                        dp[v] = dp[u] + amount[v];
                    q.push(v);
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i < leaf.size(); i++)
            ans = max(ans, dp[leaf[i]]);
        return ans;       
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        this->amount = amount;
        int n = edges.size()+1;
        adj.resize(n);
        par.resize(n);
        dp.resize(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0);
        return bfs(0, bob);
    }
};