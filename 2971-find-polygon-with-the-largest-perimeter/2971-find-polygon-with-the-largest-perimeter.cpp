#pragma GCC optimize("O3, unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool __io_boost = [](){
    cin.tie(nullptr); cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);      
}();

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long sum = nums[0];
        long long ans = -1;
        for(int i = 1; i < n; i++){
            if(i >= 2 && sum > nums[i])
                ans = sum+nums[i];
            sum += nums[i];
        }
        return ans;
    }
};