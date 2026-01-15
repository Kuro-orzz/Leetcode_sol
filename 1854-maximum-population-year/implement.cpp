class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();
        vector<int> year(1006);
        for (auto &it : logs) {
            year[it[0] - 1950]++;
            year[it[1] - 1950]--;
        }
        int ans = 0;
        int sum = 0, cur_mx = 0;
        for (int i = 0; i < year.size(); i++) {
            sum += year[i];
            if (cur_mx < sum) {
                cur_mx = sum;
                ans = i + 1950;
            }
        }
        return ans;
    }
};