class Solution {
public:
    string frequencySort(string s) {
        pair<int, int> p[266];
        for(int i = 0; i < 266; i++)
            p[i] = {i, 0};
        for(int i = 0; i < s.length(); i++)
            p[s[i]-'0'].second++;
        sort(p, p+266, [](pair<int, int> a, pair<int, int> b){return a.second > b.second;});
        string ans = "";
        int cnt = 0;
        while(p[cnt].second > 0){
            for(int i = 0; i < p[cnt].second; i++)
                ans += p[cnt].first+'0';
            cnt++;
        }
        return ans;
    }
};