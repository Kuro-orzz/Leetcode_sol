#define all(x) (x).begin(),(x).end()

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(all(nums));
        int ans = 0;
        for (int l = 0; l < n; l++) {
            for (int r = l+1; r < n; r++) {
                int it = lower_bound(all(nums), nums[l] + nums[r]) - nums.begin();
                ans += max(0, (int)it - r - 1);
            }
        }
        return ans;
    }
};