class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<int> cnt(1001, 0);
        for (int &x : nums) cnt[x]++;
        while (original <= 1000 && cnt[original]) original *= 2;
        return original;
    }
};