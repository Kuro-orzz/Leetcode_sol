class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int k = nums[i], j = i+1;
            while(j < n && (k ^ nums[j]) == k + nums[j]){
                k |= nums[j];
                j++;
            }
            ans = max(ans, j-i);
        }
        return ans;
    }
};