class Solution {
public:
    struct dsu{
        vector<int> par, sz;
        dsu(int n): par(n), sz(n, 1){
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
            if(a != b){
                if(sz[a] < sz[b]) swap(a, b);
                par[b] = a;
                sz[a] += sz[b];
            }
        }
    };

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        dsu A(n+1), B(n+1);
        int ans = 0;
        for(int i = 0; i < edges.size(); i++){
            if(edges[i][0] == 3){
                if(A.find(edges[i][1]) != A.find(edges[i][2])){
                    A.Union(edges[i][1], edges[i][2]);
                    B.Union(edges[i][1], edges[i][2]);
                }
                else
                    ans++;
            }
        }
        for(int i = 0; i < edges.size(); i++){
            if(edges[i][0] == 1){
                if(A.find(edges[i][1]) != A.find(edges[i][2]))
                    A.Union(edges[i][1], edges[i][2]);
                else
                    ans++;
            }
            else if(edges[i][0] == 2){
                if(B.find(edges[i][1]) != B.find(edges[i][2]))
                    B.Union(edges[i][1], edges[i][2]);
                else
                    ans++;
            }
        }
        bool chA = false, chB = false;
        for(int i = 0; i < n; i++){
            if(A.sz[i] == n)
                chA = true;
            if(B.sz[i] == n)
                chB = true;
        }
        if(chA && chB)
            return ans;
        return -1;
    }
};