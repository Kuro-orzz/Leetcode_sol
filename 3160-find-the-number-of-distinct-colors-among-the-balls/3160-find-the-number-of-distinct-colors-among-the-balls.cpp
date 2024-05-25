class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mp;
        unordered_map<int, int> color;
        vector<int> ans;
        int cnt = 0;
        for(int i = 0; i < queries.size(); i++){
            if(color[queries[i][0]]){
                if(mp[color[queries[i][0]]] == 1)
                    cnt--;
                mp[color[queries[i][0]]]--;
            }
            color[queries[i][0]] = queries[i][1];
            if(!mp[queries[i][1]])
                cnt++;
            mp[queries[i][1]]++;
            ans.push_back(cnt);
        }
        return ans;
    }
};