class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int dec = 0;
        int inc = 0;
        for(int i = 0; i < nums.size(); i++){
            int tmp = i+1;
            while(tmp < nums.size() && nums[tmp-1] < nums[tmp])
                tmp++;
            inc = max(inc, tmp-i);
            tmp = i+1;
            while(tmp < nums.size() && nums[tmp-1] > nums[tmp])
                tmp++;
            dec = max(dec, tmp-i);
        }
        return max(inc, dec);
    }
};