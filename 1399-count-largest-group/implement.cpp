class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> cnt(50, 0);
        for (int i = 1; i <= n; i++) {
            int sumDigit = 0;
            int x = i;
            while (x) {
                sumDigit += x % 10;
                x /= 10;
            }
            cnt[sumDigit]++;
        }
        int ans = 0, c = 0;
        for (int i = 0; i < 50; i++) {
            if (ans < cnt[i]) {
                ans = cnt[i];
                c = 1;
            }
            else if (ans == cnt[i]) c++;
        }        
        return c;
    }
};