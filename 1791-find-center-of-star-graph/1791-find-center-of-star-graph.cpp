class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> cnt(edges.size()+2);
        for(int i = 0; i < 2; i++){
            cnt[edges[i][0]]++;
            cnt[edges[i][1]]++;
            if(cnt[edges[i][0]] > 1)
                return edges[i][0];
            if(cnt[edges[i][1]] > 1)
                return edges[i][1];
        }
        return 0;
    }
};