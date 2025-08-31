class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int idx = -1, val = 0;
        int ans = 0;
        for (int i = 0; i < dimensions.size(); i++) {
            int t = dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1];
            if (t > val || (t == val && dimensions[i][0] * dimensions[i][1] > ans)) {
                idx = i;
                val = t;
                ans = dimensions[i][0] * dimensions[i][1];
            }
        }
        return ans;
    }
};