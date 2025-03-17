class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(501, 0);
        for(int i = 0; i < n; i++)
            cnt[nums[i]]++;
        for(int i = 0; i < 501; i++)
            if(cnt[i] % 2)
                return false;
        return true;
    }
};