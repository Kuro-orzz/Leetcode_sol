class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int l = 0, r = 0;
        vector<vector<int>> res;
        while (r < n) {
            int a = intervals[l][0];
            int b = intervals[l][1];
            while (r < n && intervals[r][0] <= b) {
                b = max(b, intervals[r][1]);
                r++;
            }
            res.push_back({a, b});
            l = r;
        }
        return res;
    }
};