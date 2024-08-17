class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mark(n, 1);
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1]+1)
                mark[i] = 0;
        }
        int pos = -1;
        for(int i = 0; i < k; i++){
            if(mark[i] == 0)
                pos = i;
        }
        vector<int> ans;
        for(int i = k-1; i < n; i++){
            if(!mark[i]) pos = i;
            if(pos > i-k+1)
                ans.push_back(-1);
            else
                ans.push_back(nums[i]);
        }
        return ans;
    }
};