#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        auto cmp = [&](pair<ll, pii> a, pair<ll, pii> b){
            return a.fi > b.fi;
        };
        vector<pair<ll, pii>> t;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                t.push_back({board[i][j], {i, j}});
        }
        sort(t.begin(), t.end(), cmp);
        vector<pair<ll, pii>> v;
        unordered_set<int> row, col;
        for(int i = 0; i < t.size(); i++){
            if(row.size() <= 9 || row.count(t[i].se.fi))
                v.push_back(t[i]);
            else if(col.size() <= 9 || col.count(t[i].se.se))
                v.push_back(t[i]);
            row.insert(t[i].se.fi);
            col.insert(t[i].se.se);
            if(row.size() >= 9 && col.size() >= 9)
                break;
        }
        ll ans = -1e18;
        for(int i = 0; i < v.size(); i++){
            unordered_set<int> r, c;
            r.insert(v[i].se.fi);
            c.insert(v[i].se.se);
            for(int j = 0; j < v.size(); j++){
                if(!r.count(v[j].se.fi) && !c.count(v[j].se.se)){
                    r.insert(v[j].se.fi);
                    c.insert(v[j].se.se);
                    for(int k = 0; k < v.size(); k++)
                        if(!r.count(v[k].se.fi) && !c.count(v[k].se.se))
                            ans = max(ans, v[i].fi+v[j].fi+v[k].fi);
                    r.erase(v[j].se.fi);
                    c.erase(v[j].se.se);
                }
            }
        }
        return ans;
    }
};