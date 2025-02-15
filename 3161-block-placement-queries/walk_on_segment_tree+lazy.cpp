class Solution {
public:
    vector<int> st, lazy;

    void push(int id){
        if(lazy[id] != INT_MAX){
            st[id*2] = min(st[id*2], lazy[id]);
            st[id*2+1] = min(st[id*2+1], lazy[id]);
            lazy[id*2] = min(lazy[id*2], lazy[id]);
            lazy[id*2+1] = min(lazy[id*2+1], lazy[id]);
            lazy[id] = INT_MAX;
        }
    }

    void update(int id, int l, int r, int u, int v, int val){
        if(l > v || r < u) return;
        if(l >= u && r <= v){
            st[id] = min(st[id], val);
            lazy[id] = min(lazy[id], val);
            return;
        }
        push(id);
        int mid = (l+r)>>1;
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        st[id] = max(st[id*2], st[id*2+1]);
    }

    int getMax(int id, int l, int r, int u, int v){
        if(l > v || r < u) return 0;
        if(l >= u && r <= v) return st[id];
        push(id);
        int mid = (l+r)>>1;
        if(v <= mid) return getMax(id*2, l, mid, u, v);
        else if (u >= mid+1) return getMax(id*2+1, mid+1, r, u, v);
        return max(getMax(id*2, l, mid, u, v), getMax(id*2+1, mid+1, r, u, v));
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        int N = min(50000, 3*(int)queries.size());
        st.resize(4*N+6, INT_MAX);
        lazy.resize(4*N+6, INT_MAX);
        vector<bool> ans;
        set<int> s;
        s.insert(1);
        for(int i = 0; i < queries.size(); i++){
            if(queries[i][0] == 1){
                queries[i][1]++;
                s.insert(queries[i][1]);
                auto it = s.find(queries[i][1]);
                if(it != s.begin()){
                    int dist = *it-*prev(it);
                    update(1, 1, N, *prev(it), *it, dist);
                }
                if(it != prev(s.end())){
                    int dist = *next(it)-*it;
                    update(1, 1, N, *it, *next(it), dist);
                }
            }
            else{
                if(queries[i][1] < queries[i][2]){
                    ans.push_back(false);
                    continue;
                }
                auto it = s.lower_bound(queries[i][1]+1);
                int d1 = queries[i][1]+1-*prev(it);
                int d2 = getMax(1, 1, N, 1, *prev(it));
                if(max(d1, d2) < queries[i][2])
                    ans.push_back(false);
                else ans.push_back(true);
            }
        }
        return ans;
    }
};