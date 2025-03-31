class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int, int>> v(26, {-1, -1});
        for(int i = 0; i < s.size(); i++){
            if(v[s[i]-'a'].first == -1)
                v[s[i]-'a'].first = i;
            else
                v[s[i]-'a'].second = i;
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        pair<int, int> cur = {0, 0};
        for(int i = 0; i < 26; i++){
            if(v[i].first == -1) continue;
            if(v[i].first <= cur.second && v[i].second != -1)
                cur.second = max(cur.second, v[i].second);
            else if(v[i].first > cur.second){
                ans.push_back(cur.second+1-cur.first);
                cur = v[i];
                cur.second = max(cur.second, v[i].first);
            }
        }
        ans.push_back(cur.second+1-cur.first);
        return ans;
    }
};