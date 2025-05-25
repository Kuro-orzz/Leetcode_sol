class Dsu{
public:
	vector<int> par, sz;
	Dsu(int n): par(n), sz(n, 1){
		for(int i = 0; i < par.size(); i++)
			par[i] = i;
	}
	int find(int v){
		if(v == par[v])
			return v;
		return par[v] = find(par[v]);
	}
	void merge(int a, int b){
		a = find(a);
		b = find(b);
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			par[b] = a;
			sz[a] += sz[b];
		}
	}
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        Dsu g(n+1);
        for (int i = 0; i < n; i++) {
            if (g.find(i) != i || i == n-1) continue;
            int j = i;
            while (j+1 < n && nums[j+1]-nums[j] <= maxDiff) {
                g.merge(i, j+1);
                j++;
            }
        }
        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++) {
            if (g.find(queries[i][0]) == g.find(queries[i][1]))
                ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};