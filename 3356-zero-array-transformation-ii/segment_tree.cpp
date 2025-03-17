struct Segtree{
	vector<int> st, lazy;
    
    Segtree(){}
    Segtree(int n): st(n*4), lazy(n*4){}

    void push(int id){
        if(lazy[id]){
            st[id*2] += lazy[id];
            st[id*2+1] += lazy[id];
            lazy[id*2] += lazy[id];
            lazy[id*2+1] += lazy[id];
            lazy[id] = 0;
        }
    }
    int get(int id, int l, int r, int u, int v){
        if(r < u || v < l)
            return 0;
        if(u <= l && v >= r)
            return st[id];
        push(id);
        int mid = (l+r)>>1;
        int t1 = get(id*2, l, mid, u, v);
        int t2 = get(id*2+1, mid+1, r, u, v);
        return max(t1, t2);
    }
    void update(int id, int l, int r, int u, int v, int val){
        if(v < l || u > r)
            return;
        if(u <= l && v >= r){
            st[id] += val;
            lazy[id] += val;
            return;
        }
        push(id);
        int mid = (l+r)>>1;
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        st[id] = max(st[id*2], st[id*2+1]);
    }
};

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        Segtree stree(n);  
        for(int i = 0; i < nums.size(); i++)
            stree.update(1, 1, n, i+1, i+1, nums[i]);
        int ans = 0;
        while(ans < m && stree.get(1, 1, n, 1, n) > 0){
            int l = queries[ans][0], r = queries[ans][1];
            int val = queries[ans][2];
            stree.update(1, 1, n, l+1, r+1, -val);
            ans++;
        }
        if(stree.get(1, 1, n, 1, n) > 0)
            return -1;
        return ans;    
    }
};