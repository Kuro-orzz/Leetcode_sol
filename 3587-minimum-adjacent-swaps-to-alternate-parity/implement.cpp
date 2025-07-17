class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> odd, even;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2) odd.push_back(i);
            else even.push_back(i);
        }
        int n = odd.size(), m = even.size();
        if (abs(n-m) > 1) return -1;
        int ans = 0;
        if (n > m) {
            int p1 = 0, p2 = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (i % 2 == 0) ans += max(0, odd[p1++] - i);
                else ans += max(0, even[p2++]-i);
            }
        } else if (n < m) {
            int p1 = 0, p2 = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (i % 2 == 0) ans += max(0, even[p1++] - i);
                else ans += max(0, odd[p2++]-i);
            }
        } else {
            int res1 = 0;
            int p1 = 0, p2 = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (i % 2 == 0) res1 += max(0, odd[p1++] - i);
                else res1 += max(0, even[p2++]-i);
            }
            int res2 = 0;
            p1 = 0, p2 = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (i % 2 == 0) res2 += max(0, even[p1++] - i);
                else res2 += max(0, odd[p2++]-i);
            }
            ans = min(res1, res2);
        }
        return ans;
    }
};