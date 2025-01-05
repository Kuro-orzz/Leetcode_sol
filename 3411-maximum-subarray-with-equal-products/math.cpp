class Solution {
public:
    int __lcm(int a, int b){
        return a*b/__gcd(a, b);
    }

    int maxLength(vector<int>& nums) {
        int ans = 0;
        int multi, lcm, gcd;
        for(int i = 0; i < nums.size(); i++){
            multi = nums[i];
            lcm = nums[i];
            gcd = nums[i];
            if(multi == lcm * gcd)
                ans = max(ans, 1);
            for(int j = i+1; j < nums.size(); j++){
                multi *= nums[j];
                lcm = __lcm(lcm, nums[j]);
                gcd = __gcd(gcd, nums[j]);
                if(multi == lcm * gcd) 
                    ans = max(ans, j-i+1);
                if(multi > 1e7) break;
            }
        }
        return ans;
    }
};