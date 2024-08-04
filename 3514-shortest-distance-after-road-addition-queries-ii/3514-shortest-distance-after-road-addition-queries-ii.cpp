class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        set<int> s;
        for(int i = 0; i < n; i++)
            s.insert(i);
        for(int i = 0; i < queries.size(); i++){
            int a = queries[i][0];
            int b = queries[i][1];
            while(s.upper_bound(a) != s.end() && *s.upper_bound(a) < b)
                s.erase(s.upper_bound(a));
            res.push_back(s.size()-1);
        }
        return res;
    }
};