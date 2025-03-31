#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pii> vertical, horizontal;
        for(auto it : rectangles){
            vertical.push_back({it[0], 1});
            vertical.push_back({it[2], -1});
            horizontal.push_back({it[1], 1});
            horizontal.push_back({it[3], -1});
        }
        sort(vertical.begin(), vertical.end());
        sort(horizontal.begin(), horizontal.end());
        int v = 0, h = 0;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < vertical.size(); i++){
            cnt1 += vertical[i].se;
            cnt2 += horizontal[i].se;
            if(!cnt1) v++;
            if(!cnt2) h++;
        }
        return v >= 3 || h >= 3;
    }
};