class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({firstList[i][0], 0});
            v.push_back({firstList[i][1], 1});
        }
        for(int i = 0; i < m; i++){
            v.push_back({secondList[i][0], 0});
            v.push_back({secondList[i][1], 1});
        }
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        int cnt = 0;        
        for(int i = 0; i < v.size(); i++){
            if(v[i].second == 0) cnt++;
            else cnt--;
            if(cnt == 2){
                ans.push_back({v[i].first, v[i+1].first});
                cnt--; i++;
            }
        }
        return ans;
    }
};