class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pref(n+1);
        for (size_t i = 0; i < queries.size(); i++) {
            pref[queries[i][0]]++, pref[queries[i][1]+1]--;
        }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += pref[i];
            if (nums[i] - sum > 0) return false;
        }
        return true;
    }
};
