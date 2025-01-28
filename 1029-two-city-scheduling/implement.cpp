class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        auto cmp = [&](vector<int> a, vector<int> b){
            return abs(a[0]-a[1]) > abs(b[0]-b[1]);
        };
        sort(costs.begin(), costs.end(), cmp);
        int ans = 0;
        vector<int> cnt(2, 0);
        for(int i = 0; i < costs.size(); i++){
            if(costs[i][0] < costs[i][1]){
                if(cnt[0] < n){
                    ans += costs[i][0];
                    cnt[0]++;
                }
                else{
                    ans += costs[i][1];
                    cnt[1]++;
                }
            }
            else{
                if(cnt[1] < n){
                    ans += costs[i][1];
                    cnt[1]++;
                }
                else{
                    ans += costs[i][0];
                    cnt[0]++;
                }
            }
        }
        return ans;
    }
};