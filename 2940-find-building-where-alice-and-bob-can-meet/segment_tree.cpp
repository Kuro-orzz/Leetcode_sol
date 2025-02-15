class Solution {
public:
    int st[200006];

    void update(int id, int l, int r, int pos, int val){
        if(l > pos || r < pos) return;
        if(l == r){
            st[id] = val;
            return;
        }
        int mid = (l + r) >> 1;
        update(id*2, l, mid, pos, val);
        update(id*2+1, mid+1, r, pos, val);
        st[id] = max(st[id*2], st[id*2+1]);
    }

    int get(int id, int l, int r, int u, int v, int val1, int val2){
        if(l > v || r < u) return -1;
        if(l == r && l >= u && l <= v) return l-1;
        int mid = (l + r) >> 1;
        int t1 = -1;
        if(st[id*2] > val1 && st[id*2] > val2)
            t1 = get(id*2, l, mid, u, v, val1, val2);
        if(t1 != -1) return t1;
        if(st[id*2+1] > val1 && st[id*2+1] > val2)
            return get(id*2+1, mid+1, r, u, v, val1, val2);
        return -1;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        for(int i = 0; i < n; i++)
            update(1, 1, n, i+1, heights[i]);
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int a = queries[i][0];
            int b = queries[i][1];
            if(a > b) swap(a, b);
            if(a == b) 
                ans.push_back(a);
            else if(heights[a] == heights[b])
                ans.push_back(get(1, 1, n, b+2, n, heights[a], heights[b]));
            else if(heights[a] < heights[b]) 
                ans.push_back(b);
            else 
                ans.push_back(get(1, 1, n, b+1, n, heights[a], heights[b]));
        }
        return ans;
    }
};