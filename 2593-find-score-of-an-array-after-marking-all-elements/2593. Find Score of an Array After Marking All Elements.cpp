class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        vector<int> vis(nums.size(), 0);
        vector<pair<int, int>> v;
        for(int i = 0; i < nums.size(); i++)
            v.push_back({nums[i], i});
        sort(v.begin(), v.end());
        for(int i = 0; i < nums.size(); i++){
            if(vis[v[i].second]) continue;
            vis[v[i].second] = 1;
            ans += v[i].first;
            int l = v[i].second-1;
            int r = v[i].second+1;
            if(l >= 0) vis[l] = 1;
            if(r < nums.size()) vis[r] = 1;
        }
        return ans;
    }
};