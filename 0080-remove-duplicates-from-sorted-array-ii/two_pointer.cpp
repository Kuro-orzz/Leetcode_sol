class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        int ans = 0;
        int l = 1, r = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]) cnt++;
            else cnt = 1;
            if(cnt == 3){
                cnt = 1;
                while(r < nums.size() && nums[r] == nums[i]) r++;
                i = r;
            }
            if(r == nums.size()) continue;
            nums[l] = nums[r];
            l++; r++;
            
        }
        return l;
    }
};