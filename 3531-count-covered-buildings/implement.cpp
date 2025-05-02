class Solution {
public:
    const int maxn = 1e5+6;
    
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int ans = 0;
        set<int> x[maxn], y[maxn];
        for (int i = 0; i < buildings.size(); i++) {
            x[buildings[i][1]].insert(buildings[i][0]);
            y[buildings[i][0]].insert(buildings[i][1]);
        }
        for (int i = 0; i < buildings.size(); i++) {
            int a = buildings[i][0];
            int b = buildings[i][1];
            if (*x[b].begin() == a) continue;  // Left
            if (*x[b].rbegin() == a) continue; // Right
            if (*y[a].rbegin() == b) continue; // Up
            if (*y[a].begin() == b) continue;  // Down
            ans++;
        }
        return ans;
    }
};