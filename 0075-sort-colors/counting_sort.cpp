class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(3, 0);
        for(int i : nums)
            v[i]++;
        int p = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < v[i]; j++){
                nums[p] = i;
                p++;
            }
    }
};