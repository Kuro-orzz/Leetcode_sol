class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;
        int ans = 0;
        int i = 1, cnt = 0;
        while (i < n && nums[i-1] < nums[i]) {
            cnt++; i++;
        }
        ans += (cnt ? 1 : 0);
        cnt = 0;
        while (i < n && nums[i-1] > nums[i]) {
            cnt++; i++;
        }
        ans += (cnt ? 1 : 0);
        cnt = 0;
        while (i < n && nums[i-1] < nums[i]) {
            cnt++; i++;
        }
        ans += (cnt ? 1 : 0);
        return ans == 3 && i == n;
    }
};