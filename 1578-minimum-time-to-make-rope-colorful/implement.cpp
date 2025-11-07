class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        for (int i = 0; i < n-1; i++) {
            int sum = neededTime[i], mx = neededTime[i];
            while (colors[i] == colors[i+1]) {
                sum += neededTime[i+1];
                mx = max(mx, neededTime[i+1]);
                i++;
            }
            ans += sum - mx;
        }
        return ans;
    }
};