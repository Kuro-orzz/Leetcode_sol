class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<string> tmp = strs;
        for(int i = 0; i < strs.size(); i++){
            sort(tmp[i].begin(), tmp[i].end());
            mp[tmp[i]].push_back(strs[i]);
        }
        vector<vector<string>> ans(mp.size());
        int cnt = 0;
        for(auto it : mp){
            for(string x : it.second)
                ans[cnt].push_back(x);
            cnt++;
        }
        return ans;
    }
};