class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp = nums;
        int nearest = n+1;
        int cntOne = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) cntOne++;
            int cur = nums[i];
            for (int j = i+1; j < n; j++) {
                cur = gcd(cur, nums[j]);
                if (cur == 1) {
                    nearest = min(nearest, j-i);
                }    
            }
        }
        if (cntOne) return n - cntOne;
        if (nearest == n+1) return -1;
        return nearest + n - 1;
    }
};