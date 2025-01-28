class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++)
            v[i] = {nums[i], i};
        sort(v.begin(), v.end());
        vector<int> ans(n);
        vector<int> val, idx;
        for(int i = 0; i < n; i++){
            if(!i || v[i].first-v[i-1].first <= limit){
                val.push_back(v[i].first);
                idx.push_back(v[i].second);
            }
            else{
                sort(idx.begin(), idx.end());
                for(int i = 0; i < val.size(); i++)
                    ans[idx[i]] = val[i];
                val.clear();
                idx.clear();
                val.push_back(v[i].first);
                idx.push_back(v[i].second);
            }
        }
        sort(idx.begin(), idx.end());
        for(int i = 0; i < val.size(); i++)
            ans[idx[i]] = val[i];
        return ans;
    }
};