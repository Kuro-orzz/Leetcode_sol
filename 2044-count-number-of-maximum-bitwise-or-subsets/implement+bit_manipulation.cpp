class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, cnt = 0;
        for (int i = 1; i < (1 << n); i++) {
            int cal = 0;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) cal |= nums[j];
            }
            if (cal == ans) cnt++;
            else if (cal > ans) ans = cal, cnt = 1;
        }
        return cnt;
    }
};