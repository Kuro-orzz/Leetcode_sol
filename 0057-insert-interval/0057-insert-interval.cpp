class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool fin = false;
        for(int i = 0; i < intervals.size(); i++){
            if(!fin && intervals[i][0] > newInterval[1]){
                ans.push_back(newInterval);
                fin = true;
            }
            if(intervals[i][1] < newInterval[0] || intervals[i][0] > newInterval[1])
                ans.push_back(intervals[i]);
            else{
                newInterval[0] = min({newInterval[0], intervals[i][0], newInterval[0]});
                newInterval[1] = max({newInterval[1], intervals[i][1], newInterval[1]});
            }
        }
        if(!fin)
            ans.push_back(newInterval);
        return ans;
    }
};