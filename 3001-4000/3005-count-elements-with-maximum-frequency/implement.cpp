class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> fre(106);
        for (int i = 0; i < n; i++) fre[nums[i]]++;
        int ans = 0, max_fre = 0;
        for (auto &x : fre) {
            if (x > max_fre) {
                max_fre = x;
                ans = x;
            } else if (x == max_fre) {
                ans += x;
            }
        }
        return ans;
    }
};