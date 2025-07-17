class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<int> dp(4), lastNum = {-1, -1, -1, -1};
        // (0, 0), (0, 1), (1, 0), (1, 1)
        for (int x : nums) {
            x %= 2;
            if (lastNum[0] == -1 && x % 2 == 0) {
                dp[0] = dp[1] = 1;
                lastNum[0] = lastNum[1] = x;
            } else if (lastNum[0] != -1) {
                if (lastNum[0] ^ x == 0) dp[0]++;
                if (lastNum[1] ^ x) dp[1]++, lastNum[1] ^= 1;
            }
            if (lastNum[2] == -1 && x % 2) {
                dp[2] = dp[3] = 1;
                lastNum[2] = lastNum[3] = x;
            } else if (lastNum[2] != -1) {
                if (lastNum[2] ^ x) dp[2]++, lastNum[2] ^= 1;
                if (lastNum[3] ^ x == 0) dp[3]++;
            }
        }
        return max({dp[0], dp[1], dp[2], dp[3]});
    }
};