class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost;
        set<int> st;
        for(const auto &x : matches){
            lost[x[1]]++;
            st.insert(x[0]);
            st.insert(x[1]);
        }
        vector<vector<int>> ans(2);
        for(const auto &x : st){
            if(lost[x] == 0)
                ans[0].push_back(x);
            else if(lost[x] == 1)
                ans[1].push_back(x);
        }
        return ans;
    }
};