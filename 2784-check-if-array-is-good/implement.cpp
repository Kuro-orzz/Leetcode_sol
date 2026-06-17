class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;
        vector<int> cnt(201);
        for (int x : nums) cnt[x]++;
        for (int i = 1; i < n-1; i++) {
            if (cnt[i] != 1) return false;
        }
        return cnt[n-1] == 2;
    }
};