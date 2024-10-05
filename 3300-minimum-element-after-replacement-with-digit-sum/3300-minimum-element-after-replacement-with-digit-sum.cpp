class Solution {
public:
    int sumDigit(int x){
        int ans = 0;
        while(x){
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }

    int minElement(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            nums[i] = sumDigit(nums[i]);
        int ans = 100;
        for(int x : nums)
            ans = min(ans, x);
        return ans;
    }
};