#define all(x) (x).begin(),(x).end()

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 1; i <= nums.back(); i++) {
            int cnt = 0;
            // less than
            auto less_l = lower_bound(all(nums), i-k);
            // equal
            auto equal_l = lower_bound(all(nums), i);
            auto equal_r = upper_bound(all(nums), i);
            cnt += equal_r - equal_l;
            // greater than
            auto greater_r = upper_bound(all(nums), i+k);
            
            int equal = equal_r - equal_l;
            int less = equal_l - less_l;
            int greater = greater_r - equal_r;
            ans = max(ans, equal + min(numOperations, less + greater));
        }
        return ans;
    }
};