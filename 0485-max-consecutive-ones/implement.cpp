class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for (int &x : nums) {
            if (x == 1) cnt++;
            else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        return ans = max(ans, cnt);
    }
};