class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        mt19937 rng(time(0));
        int n = nums.size();
        unordered_set<int> s, a;
        for (int i = 0; i < 30; i++) {
            int x = rng() % n;
            s.insert(x);
        }
        for (int x : s) {
            if (a.find(nums[x]) != a.end()) return nums[x];
            a.insert(nums[x]);
        }
        return 0;
    }
};