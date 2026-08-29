class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int> cnt(value);
        int max_MEX = 0;
        for (int x : nums) {
            cnt[(x % value + value) % value]++;
            while (cnt[max_MEX % value]) cnt[max_MEX % value]--, max_MEX++;
        }
        return max_MEX;
    }
};