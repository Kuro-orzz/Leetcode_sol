class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        int t = customers[0][0];
        for(int i = 0; i < customers.size(); i++){
            t = max(t, customers[i][0]) + customers[i][1];
            ans += t-customers[i][0]; 
        }
        return ans/customers.size();
    }
};