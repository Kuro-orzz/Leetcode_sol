#define all(x) (x).begin(),(x).end()

class Solution {
public:
    int check(vector<int> &nums, long long target, int k, int numOperations) {
        // less than
        auto less_l = lower_bound(all(nums), target-k);
        // equal
        auto equal_l = lower_bound(all(nums), target);
        auto equal_r = upper_bound(all(nums), target);
        // greater than
        auto greater_r = upper_bound(all(nums), target+k);
        
        int equal = equal_r - equal_l;
        int less = equal_l - less_l;
        int greater = greater_r - equal_r;

        return equal + min(numOperations, less + greater);
    }

    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, check(nums, nums[i] - k, k, numOperations));
            ans = max(ans, check(nums, nums[i], k, numOperations));
            ans = max(ans, check(nums, nums[i] + k, k, numOperations));
        }
        return ans;
    }
};