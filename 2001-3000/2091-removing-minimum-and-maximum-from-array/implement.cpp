class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int pos_mx = 0, pos_mn = 0;
        for (int i = 0; i < n; i++) {
            if (nums[pos_mx] < nums[i]) {
                pos_mx = i;
            }
            if (nums[pos_mn] > nums[i]) {
                pos_mn = i;
            }
        }
        int mx = max(pos_mx, pos_mn);
        int mn = min(pos_mx, pos_mn);
        int left_right = n - mx + mn + 1;
        int left_left = mx + 1;
        int right_right = n - mn;
        return min({left_right, left_left, right_right});
    }
};