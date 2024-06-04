class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        int n = nums.size();
        vector<int> pre(n, 0);
        for(int i = 1; i < n; i++){ 
            if(((nums[i-1] ^ nums[i]) & 1) == 0)
                pre[i] = pre[i-1]+1;
            else
                pre[i] = pre[i-1];
        }
        for(int i = 0; i < queries.size(); i++){
            if(pre[queries[i][0]] != pre[queries[i][1]])
                ans.push_back(false);
            else
                ans.push_back(true);
        }
        return ans;
    }
};