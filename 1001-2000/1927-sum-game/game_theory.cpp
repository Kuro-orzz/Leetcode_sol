class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sum1 = 0, sum2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (i < n/2) {
                if (num[i] == '?') cnt1++;
                else sum1 += num[i] - '0';
            } else {
                if (num[i] == '?') cnt2++;
                else sum2 += num[i] - '0';
            }
        }
        if ((cnt1 & 1) != (cnt2 & 1)) return true;
        return sum1 - sum2 != (cnt2 - cnt1) * 9 / 2;
    }
};