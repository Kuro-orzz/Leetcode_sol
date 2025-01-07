class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums[0].size();
        for(int i = 0; i < queries.size(); i++){
            priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> pq;
            for(int j = 0; j < nums.size(); j++)
                pq.push({nums[j].substr(n-queries[i][1]), j});
            int k = queries[i][0]-1;
            while(k){
                pq.pop();
                k--;
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};