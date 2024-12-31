class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, INT_MAX);
        queue<int> q;
        int tmp[3] = {1, 7, 30};
        for(int i = 0; i < 3; i++){
            auto it = upper_bound(days.begin(), days.end(), days[0]+tmp[i]-1)-days.begin();
            it--;
            if(it < 0) continue;
            dp[it] = min(dp[it], costs[i]);
            if(it < n-1) q.push(it);
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < 3; i++){
                auto it = upper_bound(days.begin(), days.end(), days[u+1]+tmp[i]-1)-days.begin();
                it--;
                if(dp[it] > dp[u] + costs[i]){
                    dp[it] = dp[u] + costs[i];
                    if(it < n-1) q.push(it);
                }
            }
        }
        return dp[n-1];
    }
};