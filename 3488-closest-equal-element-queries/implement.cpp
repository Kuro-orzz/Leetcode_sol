class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        unordered_map<int, vector<int>> mp;
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[i] = mp[nums[i]].size();
            mp[nums[i]].push_back(i);
        }
        vector<int> ans(m, -1);
        for (int i = 0; i < m; i++) {
            int val = nums[queries[i]];
            int sz = mp[val].size();
            if (sz == 1) continue;
            int cur_idx = mp[val][pos[queries[i]]];
            int prev_idx = mp[val][(pos[queries[i]] - 1 + sz) % sz];
            int next_idx = mp[val][(pos[queries[i]] + 1) % sz];
            ans[i] = min({abs(cur_idx - prev_idx), abs(cur_idx - next_idx),
                        cur_idx + n - prev_idx, cur_idx + n - next_idx,
                        prev_idx + n - cur_idx, next_idx + n - cur_idx});
        }
        return ans;
    }
};