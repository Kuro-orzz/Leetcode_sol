class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> cnt(1e5+6);
        for (int i = n-1; i >= 0; i--) {
            if (!cnt[nums[i]]) cnt[nums[i]] = 1;
            else return i / 3 + 1;
        }
        return 0;
    }
};