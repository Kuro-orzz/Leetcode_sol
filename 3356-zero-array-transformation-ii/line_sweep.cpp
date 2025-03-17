class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> freq(n+1, 0);
        int sum = 0, k = 0;
        for(int i = 0; i < n; i++){
            for(; sum + freq[i] < nums[i]; k++){
                if(k == m)
                    return -1;
                int l = queries[k][0], r = queries[k][1];
                int val = queries[k][2];
                if(i > r) continue;
                freq[max(l, i)] += val;
                freq[r+1] -= val;
            }
            sum += freq[i];
        }
        return k;
    }
};