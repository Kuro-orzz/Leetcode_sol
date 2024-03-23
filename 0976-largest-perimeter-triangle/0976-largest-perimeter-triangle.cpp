class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        auto check = [&](int a, int b, int c){
            if(a+b<=c || b+c<=a || c+a<=b)
                return false;
            return true;
        };
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size()-2; i++)
            if(check(nums[i], nums[i+1], nums[i+2]))
                ans = max(ans, nums[i]+nums[i+1]+nums[i+2]);
        return ans;
    }
};