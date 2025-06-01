class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0;
        for (int i = 0; i <= min(n, limit); i++) {
            if (n - i > 2 * limit) continue;
            int cur = n - i;
            ans += min(cur + 1, abs(cur - 2 * limit) + 1);
        }
        return ans;
    }
};