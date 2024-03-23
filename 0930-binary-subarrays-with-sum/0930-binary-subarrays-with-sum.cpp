class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        int l = 0, r = 0;
        int ans = 0;
        int ctz = 0;
        while(l < nums.size()){
            bool equal = true;
            if(sum <= goal){
                sum += nums[l];
                l++;
            }
            while(sum > goal){
                sum -= nums[r];
                r++;
                ctz = 0;
                equal = false;
            }
            while(nums[r] == 0 && r < l-1){
                ctz++;
                r++;
            }
            if(sum == goal && (goal != 0 || equal)){
                ans += ctz+1;
                cout << r << " " << l << " " << ans << endl;
            }
        }
        
        return ans;
    }
};