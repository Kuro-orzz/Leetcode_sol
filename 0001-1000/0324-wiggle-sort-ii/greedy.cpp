class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end(), greater<int>());
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                nums[i] = tmp[i / 2];
            } else {
                nums[i] = tmp[i / 2 + n / 2];
            }
        }
    }
};