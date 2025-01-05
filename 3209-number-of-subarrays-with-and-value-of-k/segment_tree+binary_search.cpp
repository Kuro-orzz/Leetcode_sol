class Solution {
public:
    int st[400006];

    void update(int id, int l, int r, int pos, int val){
        if(l > pos || r < pos) return;
        if(l == r){
            st[id] = val;
            return;
        }
        int mid = (l+r)>>1;
        update(id*2, l, mid, pos, val);
        update(id*2+1, mid+1, r, pos, val);
        st[id] = st[id*2] & st[id*2+1];
    }

    int get(int id, int l, int r, int u, int v){
        if(l > v || r < u) return INT_MAX;
        if(l >= u && r <= v) return st[id];
        int mid = (l+r)>>1;
        return get(id*2, l, mid, u, v) & get(id*2+1, mid+1, r, u, v);
    }

    int lb(int lo, int hi, int k, int n){
        int l = lo;
        while(lo < hi){
            int mid = (lo+hi)>>1;
            int val = get(1, 1, n, l+1, mid+1);
            if(val == k) hi = mid;
            else if(val > k) lo = mid+1;
            else if(val < k) hi = mid-1;
        }
        return hi;
    }

    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
            update(1, 1, n, i+1, nums[i]);
        int l = 0;
        long long ans = 0;
        while(l < n){
            int t1 = lb(l, n-1, k, n);
            int t2 = lb(l, n-1, k-1, n);
            int t = get(1, 1, n, l+1, t1+1);
            if(t != k){
                l++; continue;
            }
            ans += t2-t1+1;
            if(get(1, 1, n, l+1, t2+1) < k) ans--;
            l++;
        }
        return ans;
    }
};