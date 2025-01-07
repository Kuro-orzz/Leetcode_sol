class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++)
            v[i] = {ratings[i], i};
        sort(v.begin(), v.end());
        vector<int> t(n+2, 0);
        for(int i = 0; i < n; i++){
            int idx = v[i].second;
            int a = (idx-1 >= 0 && ratings[idx] == ratings[idx-1] ? 1 : t[idx]+1);
            int b = (idx+1 < n && ratings[idx] == ratings[idx+1] ? 1 : t[idx+2]+1);
            t[idx+1] = max(a, b);
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++)
            ans += t[i];
        return ans;
    }
};