class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int mod = 1e9+7;
        set<int> s;
        for(int i = 0; i < rectangles.size(); i++)
            s.insert(rectangles[i].begin(), rectangles[i].end());
        int cnt = 1;
        unordered_map<int, int> mp, rev;
        for(int x : s){
            mp[x] = cnt;
            rev[cnt++] = x;
        }
        int a[cnt][cnt];
        memset(a, 0, sizeof a);
        for(int i = 0; i < rectangles.size(); i++){
            int l = mp[rectangles[i][0]], r = mp[rectangles[i][2]];
            for(int j = mp[rectangles[i][1]]; j < mp[rectangles[i][3]]; j++){
                a[j][l]++;
                a[j][r]--;
            }
        }
        int ans = 0;
        for(int i = 0; i < cnt; i++)
            for(int j = 1; j < cnt; j++){
                a[i][j] += a[i][j-1];
                if(!a[i][j]) continue;
                ans = (ans + 1ll*(rev[j+1]-rev[j])*(rev[i+1]-rev[i])) % mod;
            }
        return ans;
    }
};