class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<map<int, int>> v(n);
        for(int i = 0; i < pick.size(); i++)
            v[pick[i][0]][pick[i][1]]++;
        set<int> s;
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(auto it : v[i])
                if(it.second >= i+1){
                    s.insert(i);
                    break;
                }
        }
        return s.size();
    }
};