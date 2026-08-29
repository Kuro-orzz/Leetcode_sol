class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int cnt_weeks = n / 7;
        int firstWeek = 7 * (1 + 7) / 2;
        int lastWeek = 7 * (cnt_weeks + cnt_weeks + 6) / 2;
        ans += cnt_weeks * (firstWeek + lastWeek) / 2;
        n = n % 7;
        ans += n * (cnt_weeks + 1 + cnt_weeks + n) / 2;
        return ans;
    }
};