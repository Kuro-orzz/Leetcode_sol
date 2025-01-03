class Solution {
public
    int waysToSplitArray(vectorint& nums) {
        long long sum = 0;
        for(int x  nums) sum += x;
        long long t = 0;
        int ans = 0;
        for(int i = 0; i  nums.size()-1; i++){
            t += nums[i];
            if(t = sum-t) ans++;
        }
        return ans;
    }
};