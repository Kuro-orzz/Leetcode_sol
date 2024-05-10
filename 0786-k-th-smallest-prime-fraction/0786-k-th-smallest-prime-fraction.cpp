class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int, int>> v;
        int n = arr.size();
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                v.push_back({arr[i], arr[j]});
        auto cmp = [&](pair<int, int> a, pair<int, int> b){
            return (double)a.first/a.second < (double)b.first/b.second;
        };
        sort(v.begin(), v.end(), cmp);
        vector<int> ans = {v[k-1].first, v[k-1].second};
        return ans;
    }
};