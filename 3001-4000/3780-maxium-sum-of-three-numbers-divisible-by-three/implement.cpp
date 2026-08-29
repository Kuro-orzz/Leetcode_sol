class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v(3);
        for (int x : nums) {
            v[x % 3].push_back(x);
        }
        sort(v[0].begin(), v[0].end(), greater<int>());
        sort(v[1].begin(), v[1].end(), greater<int>());
        sort(v[2].begin(), v[2].end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            if (v[i].size() >= 3) {
                ans = max(ans, v[i][0] + v[i][1] + v[i][2]);
            }
        }
        if (v[0].size() && v[1].size() && v[2].size()) {
            ans = max(ans, v[0][0] + v[1][0] + v[2][0]);
        }
        return ans;
    }
};