class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        pair<int, int> p[n];
        for(int i = 0; i < n; i++)
            p[i] = {difficulty[i], profit[i]};
        sort(p, p+n);
        for(int i = 0; i < n; i++){
            difficulty[i] = p[i].first;
            profit[i] = p[i].second;
        }
        vector<int> max_profit(n);
        int t = 0;
        for(int i = 0; i < n; i++){
            t = max(t, profit[i]);
            max_profit[i] = t;
        }
        int ans = 0;
        for(int i = 0; i < worker.size(); i++){
            auto it = upper_bound(difficulty.begin(), difficulty.end(), worker[i]);
            if(it-difficulty.begin() > 0)
                ans += max_profit[it-difficulty.begin()-1];
        }
        return ans;
    }
};