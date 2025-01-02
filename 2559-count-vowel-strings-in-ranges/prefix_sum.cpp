class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        unordered_set<char> s = {'a', 'e', 'i', 'o', 'u'};
        vector<int> pre(n+1, 0);
        for(int i = 1; i <= n; i++)
            if(s.count(words[i-1][0]) && s.count(words[i-1].back()))
                pre[i] = pre[i-1] + 1;
            else pre[i] = pre[i-1];
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            ans.push_back(pre[r+1]-pre[l]);
        }
        return ans;
    }
};