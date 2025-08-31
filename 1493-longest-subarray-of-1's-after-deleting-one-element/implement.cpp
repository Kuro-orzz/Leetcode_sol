class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> a, val;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && nums[j] == 1) j++;
            a.push_back(j-i);
            val.push_back(1);
            i = j;
            while (j < n && nums[j] != 1) j++;
            a.push_back(j-i);
            val.push_back(0);
            i = j;
        }
        int ans = 0;
        for (int i = 0; i < a.size(); i++) {
            if (!val[i]) continue;
            ans = max(ans, a[i]);
            if (i+2 < a.size() && a[i+1] == 1) {
                ans = max(ans, a[i] + a[i+2]);
            }
        }
        if (ans == nums.size()) ans--;
        return ans;
    }
};