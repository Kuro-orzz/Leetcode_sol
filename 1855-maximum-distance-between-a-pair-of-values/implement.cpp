class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        int ans = 0;
        while (i < n) {
            while (j + 1 < m && nums2[j+1] >= nums1[i]) j++;
            if (i > j) j = i + 1;
            else if (j < m && nums1[i] <= nums2[j]) ans = max(ans, j-i);
            i++;
        }
        return ans;
    }
};