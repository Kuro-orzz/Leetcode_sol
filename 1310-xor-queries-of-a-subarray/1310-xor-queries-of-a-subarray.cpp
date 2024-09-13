class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pre(arr.size()+1);
        pre[0] = 0;
        for(int i = 1; i < pre.size(); i++)
            pre[i] = pre[i-1]^arr[i-1];
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            ans.push_back(pre[r+1]^pre[l]);
        }
        return ans;
    }
};