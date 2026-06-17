class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        vector<int> v, a;
        int prevBit = -1;
        for (int i = 0; i < n; i++) {
            int c = __builtin_popcountll(nums[i]);
            if (c == prevBit) a.push_back(nums[i]);
            else {
                sort(a.begin(), a.end());
                v.insert(v.end(), a.begin(), a.end());
                a = {nums[i]};
                prevBit = c;
            }
        }
        sort(a.begin(), a.end());
        v.insert(v.end(), a.begin(), a.end());
        return sorted == v;
    }
};