class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long cnt, ans = 0;
        for (int i = 0; i < n; i++) {
            cnt = 0;
            while (i < n && !nums[i]) {
                cnt++; i++;
            }
            if (cnt) ans += cnt * (1 + cnt) / 2;
        }
        return ans;
    }
};