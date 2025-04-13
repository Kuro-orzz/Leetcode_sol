class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> mx(n, 0);
        for(int i = 0; i < n; i++) {
            if(!i) mx[i] = nums[i];
            else mx[i] = max(mx[i-1], nums[i]);
        }
        vector<int> mx_rev(n, 0);
        for(int i = n-1; i >= 0; i--) {
            if(i == n-1) mx_rev[i] = nums[i];
            else mx_rev[i] = max(mx_rev[i+1], nums[i]);
        }
        for(int i = 1; i < n-1; i++)
            ans = max(ans, 1ll* (mx[i-1] - nums[i]) * mx_rev[i+1]);
        return ans;
    }
};