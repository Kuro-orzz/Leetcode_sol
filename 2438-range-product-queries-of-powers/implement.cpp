class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1e9+7;
        vector<int> a;
        for (int i = 0; i < 32; i++) {
            if (n >> i & 1) a.push_back(1 << i);
        }
        vector<int> ans;
        for (int i = 0; i < (int)queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            ans.push_back(1);
            for (int j = l; j <= r; j++) {
                ans[i] = (1ll * ans[i] * a[j]) % mod;
            }
        }
        return ans;
    }
};