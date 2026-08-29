class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 1;
        for (int x : nums) {
            if (x < k * cnt) continue;
            else if (x == k * cnt) cnt++;
            else break;
        }
        return k * cnt;
    }
};