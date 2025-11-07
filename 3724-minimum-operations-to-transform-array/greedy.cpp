class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int flag = -1, mid = nums2.back();
        for (int i = 0; i < n; i++) {
            if (nums2[i] < mid && mid < nums1[i]) {
                flag = i;
            } else if (nums1[i] < mid && mid < nums2[i]) {
                flag = i;
            }
        }
        long long ans = 0;
        if (flag != -1) ans++;
        else {
            int mn = 1e9;
            for (int i = 0; i < n; i++) {
                mn = min({mn, abs(mid-nums1[i]), abs(mid-nums2[i])});
            }
            ans += mn + 1;
        }
        for (int i = 0; i < n; i++) {
            ans += abs(nums1[i] - nums2[i]);
        }
        return ans;
    }
};