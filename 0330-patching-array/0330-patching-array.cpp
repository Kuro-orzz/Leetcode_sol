class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        int i = 0;
        long long t = 0;
        while(t < n){
            if(i < nums.size() && t+1 >= nums[i]){
                t += nums[i];
                i++;
            }
            else{
                t += t+1;
                ans++;
            }
        }
        return ans;
    }
};