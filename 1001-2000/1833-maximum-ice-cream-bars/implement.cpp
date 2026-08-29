class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        int i = 0;
        while (i < n) {
            if (coins >= costs[i]) coins -= costs[i];
            else break;
            i++;
        }
        return i;
    }
};