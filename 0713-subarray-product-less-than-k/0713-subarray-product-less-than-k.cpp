class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0, r=0;
        int mul, ans = 0;
        while(l < nums.size()){
            r = max(r, l);
            if(l == r)
                mul = nums[l];
            if(mul < k && r < nums.size()){
                r++;
                if(r < nums.size())
                     mul *= nums[r];
            }
            else{
                ans += r-l;
                mul /= nums[l];
                l++;
            }
        }
        return ans;
    }
};