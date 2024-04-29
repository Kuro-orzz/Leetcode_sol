class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> bit(32, 0);
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < 32; j++)
                if(nums[i] & (1 << j))
                    bit[j]++;
        }
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if((k & (1 << i)) == 0){
                if(bit[i] & 1)
                    ans++;
            }
            else{
                if(!(bit[i] & 1))
                    ans++;
            }
        }
        return ans;
    }
};