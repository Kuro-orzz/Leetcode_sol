class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+1, 0);
        for(int x : nums)
            v[x] = 1;
        vector<int> ans;
        for(int i = 1; i <= n; i++)
            if(!v[i])
                ans.push_back(i);
        return ans;
    }
};