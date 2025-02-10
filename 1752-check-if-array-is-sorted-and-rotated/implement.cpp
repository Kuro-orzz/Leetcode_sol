class Solution {
public:
    bool check(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            rotate(nums.begin(), nums.begin()+1, nums.end());
            bool ch = true;
            for(int j = 1; j < nums.size(); j++)
                if(nums[j-1] > nums[j])
                    ch = false;
            if(ch) return true;
        }
        return false;
    }
};