class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums1 = {nums[0]}, nums2 = {nums[1]};
        for (int i = 2; i < n; i++) {
            if (nums1.back() > nums2.back()) {
                nums1.push_back(nums[i]);
            } else {
                nums2.push_back(nums[i]);
            }
        }
        for (int x : nums2) {
            nums1.push_back(x);
        }
        return nums1;
    }
};