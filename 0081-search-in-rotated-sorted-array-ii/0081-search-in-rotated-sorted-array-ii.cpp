class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int x : nums)
            if(x == target)
                return true;
        return false;
    }
};