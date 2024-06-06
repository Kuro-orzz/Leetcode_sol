class Solution {
public:
    vector<int> par;
    void make_set(){
        for(int i = 0; i < par.size(); i++)
            par[i] = i;
    }
    int find(int v){
        if(v == par[v])
            return v;
        return par[v] = find(par[v]);
    }
    void Union(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b)
            par[b] = a;
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        par.resize(n);
        make_set();
        for(int i = 0; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            if(par[b] == b)
                Union(a, b);
        }
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            find(i);
            s.insert(par[i]);
        }
        vector<int> ans;
        for(int x : s)
            ans.push_back(x);
        return ans;    
    }
};