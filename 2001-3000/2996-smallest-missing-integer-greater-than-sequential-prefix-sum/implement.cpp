class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int longest_seq = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1] + 1) longest_seq++;
            else break;
        }
        int ans = longest_seq * (2 * nums[0] + longest_seq - 1) / 2;
        set<int> mark(nums.begin(), nums.end());
        while (mark.count(ans)) ans++;
        return ans;
    }
};