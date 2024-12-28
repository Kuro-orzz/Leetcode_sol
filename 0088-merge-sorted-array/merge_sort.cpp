class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(nums1.size());
        std::merge(nums1.begin(), nums1.begin()+m, nums2.begin(), nums2.end(), res.begin());
        nums1 = res;
    }
};