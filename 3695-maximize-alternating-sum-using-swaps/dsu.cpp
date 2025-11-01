#define all(x) (x).begin(),(x).end()

struct Dsu {
    vector<int> par, sz;

    Dsu() {}
    Dsu(int n): par(n+1), sz(n+1, 1) {
        iota(all(par), 0);
    }

    int find(int v) {
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }

    bool same_component(int u, int v) {
        return find(u) == find(v);
    }

    int component_size(int u) {
        u = find(u);
        return sz[u];
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();
        Dsu dsu(n);
        for (int i = 0; i < swaps.size(); i++) {
            dsu.merge(swaps[i][0], swaps[i][1]);
        }
        vector<vector<int>> group(n);
        for (int i = 0; i < n; i++) {
            int gr = dsu.find(i);
            group[gr].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            vector<int> even, odd, val;
            for (int x : group[i]) {
                if (x % 2) odd.push_back(x);
                else even.push_back(x);
                val.push_back(nums[x]);
            }
            sort(all(val));
            int pos = 0;
            for (int i = 0; i < odd.size(); i++) {
                nums[odd[i]] = val[pos++];
            }
            for (int i = 0; i < even.size(); i++) {
                nums[even[i]] = val[pos++];
            }
        }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
             if (i % 2 == 0) sum += nums[i];
            else sum -= nums[i];
        }
        return sum;
    }
};