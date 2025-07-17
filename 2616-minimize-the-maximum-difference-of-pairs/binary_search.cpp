class Solution {
public:
    bool check(vector<int> &a, int val, int cnt_p) {
        for (int i = 1; i < a.size(); i++) {
            if (a[i] - a[i-1] <= val) cnt_p--, i++;
        }
        return cnt_p <= 0;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = 1e9;
        int ans = INT_MAX;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(nums, mid, p)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};