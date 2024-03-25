class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int a[100001];
        memset(a, 0, sizeof(a));
        for(int i = 0; i < nums.size(); i++)
            if(a[nums[i]] == 0)
                a[nums[i]]++;
            else
                ans.push_back(nums[i]);
        return ans;
    }
};