class Solution {
public:
    vector<vector<int>> adj;
    unordered_map<string, int> r;
    unordered_set<string> s;
    stack<int> st;
    vector<int> vis;

    void dfs(int u){
        vis[u] = 1;
        for(int v : adj[u]){
            if(vis[v]) continue;
            dfs(v);
        }
        st.push(u);
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // adj
        adj.resize(recipes.size());
        for(int i = 0; i < recipes.size(); i++)
            r[recipes[i]] = i;
        for(int i = 0; i < recipes.size(); i++){
            for(int j = 0; j < ingredients[i].size(); j++){
                if(r.count(ingredients[i][j]))
                    adj[r[ingredients[i][j]]].push_back(i);
            }
        }
        for(int i = 0; i < supplies.size(); i++)
            s.insert(supplies[i]);
        vis.resize(recipes.size());
        for(int i = 0; i < recipes.size(); i++){
            if(!vis[i])
                dfs(i);
        }
        vector<string> ans;
        while(!st.empty()){
            bool ch = true;
            int i = st.top(); st.pop();
            for(int j = 0; j < ingredients[i].size(); j++)
                if(!s.count(ingredients[i][j])){
                    ch = false;
                    break;
                }
            if(ch){
                s.insert(recipes[i]);
                ans.push_back(recipes[i]);
            }
        }
        return ans;
    }
};